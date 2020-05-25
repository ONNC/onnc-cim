#pragma once
#include "sim-module/sim_memory.hh"

template<SimObject::size_type mem_size>
class SRAM : public SimMemory<mem_size> {
public:
    SRAM(EventQueue &eq, std::string name, Bus *b, int lat, SimObject::address_type base, SimObject::size_type wid) : 
		SimMemory<mem_size>(eq, std::move(name), b, lat, base, wid) {}
    ~SRAM() override = default;
};
