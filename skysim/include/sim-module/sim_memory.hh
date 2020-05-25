#pragma once
#include <deque>
#include <fstream>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <string>
#include <sstream>

#include "sim-module/sim_object.hh"
#include "sim-module/bus.hh"

class Bus;

template <SimObject::size_type mem_size>
class SimMemory : public SimObject {
    using storage_type = std::array<unsigned char, mem_size>;

    Bus *bus;
    storage_type storage;
	address_type base_addr;
    int latency;
	size_type data_width;

public:
    SimMemory(EventQueue &eq, std::string name, Bus *b, int lat, address_type base, size_type wid) : 
		SimObject{eq, std::move(name)}, bus{b}
		, base_addr{base}, latency{lat}, data_width(wid) {}
    virtual ~SimMemory() override = default;

    void init(address_type start, std::ifstream &input_file, bool bin=false);
    void dump(address_type start, size_type len, std::ofstream &output_file, bool bin=false);
    void read(SimObject* sender, address_type addr, size_type len, transaction_id_type trans_id);
    void write(SimObject* sender, address_type addr, size_type len, data_type data);
#ifdef FASTMODEL
	void *pointer_at(address_type addr);
#endif
};

template <SimObject::size_type mem_size>
void SimMemory<mem_size>::read(SimObject* sender, address_type addr, size_type len, transaction_id_type trans_id) {
  assert(base_addr <= addr && addr+len-base_addr <= mem_size);

  scheduleEvent(latency, [=](Event&) {
    const size_type idx = addr - base_addr;

    data_type retValue(len, &storage.at(idx));
    writelog(" - %s read %d bytes from 0x%X", name.c_str(), len, addr);
#ifdef LOG
    std::cout << " (" << retValue << ')' << std::endl;
#endif

    bus->sendResponse(this, sender, [=](SimObject* sender, SimObject *receiver, Event&) {
      receiver->memReceive(addr, trans_id, retValue);
    });
  }, name+" memRead response");
}

template <SimObject::size_type mem_size>
void SimMemory<mem_size>::write(SimObject* sender, address_type addr, size_type len, data_type data) {
  assert(base_addr <= addr && addr+len-base_addr <= mem_size);
  assert(data.len == len);

  scheduleEvent(latency, [=](Event &e) {
    const size_type idx = addr - base_addr;

    // TODO: memcpy
    for(SimObject::size_type i = 0; i < data.len; ++i) {
      storage.at(idx + i) = data.data[i];
    }
    writelog(" - %s write %d bytes to 0x%X", name.c_str(), len, addr);
#ifdef LOG
    std::cout << " (" << data << ')' << std::endl;
#endif
  }, name+" memWrite done.");
}

template <SimObject::size_type mem_size>
void SimMemory<mem_size>::init(address_type start, std::ifstream &input_file, bool bin) {
	if(bin) {
		input_file.read((char*)&storage.at(start-base_addr), mem_size);
		return;
	}
	std::string line;
	address_type addr = start - base_addr;
	std::stringstream ss;
	while(getline(input_file, line)) {
		ss << line.substr(line.find("payload:")+8);
		for(size_type i=0; i<data_width; i++) {
			int byte;
			ss >> std::hex >> byte;
			storage.at(addr+i) = static_cast<unsigned char>(byte);
		}
		ss.str("");
		addr += data_width;
	}
}


template <SimObject::size_type mem_size>
void SimMemory<mem_size>::dump(address_type start, size_type len, std::ofstream &output_file, bool bin) {
	start -= base_addr;
	if(bin) {
		output_file.write((char*)&storage.at(start), len);
		return;
	}
	for(size_type i=0; i<len; i+=data_width) {
		output_file << "{offset:0x" << std::hex << i << ", size:" << std::dec << data_width << ", payload:";
		for(size_type j=0; j<data_width; j++)
			output_file << "0x" << std::setfill('0') << std::setw(2) << std::hex << 
				int(storage.at(start+i+j)) << (j==data_width-1 ? "}," : " ");
		output_file << std::endl;
	}
}

#ifdef FASTMODEL
template <SimObject::size_type mem_size>
void *SimMemory<mem_size>::pointer_at(address_type addr) {
	if(addr == 0)
		return NULL;
	return &storage.at(addr - base_addr);
}
#endif
