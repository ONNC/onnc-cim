#pragma once
#include "sim-module/sim_object.hh"
#include "sim-module/message.hh"

#include <cassert>
#include <memory>
#include <vector>
#include <unordered_map>
#include <queue>

class Bus : public SimObject {
public:
    using ReqResHandler = std::function<void(SimObject *sender, SimObject *receiver, Event &)>;

private:
    const unsigned ARBITRATION_DELAY{1};
    std::vector<SimObject *> masters;
    unsigned winner{0};
    uint64_t number_of_events{0};
    std::vector<SimObject *> slaves;

	std::vector< std::pair<address_type, size_type> > segments;
    std::unordered_map<SimObject *, std::queue<std::function<void(Event &)>>> master_request_queue;

public:
    Bus(EventQueue &eq, std::string name) : SimObject{eq, std::move(name)} { }
    ~Bus() override = default;

    void addMaster(SimObject *obj);
    void addSlave(SimObject *obj, std::pair<address_type, size_type> seg);
    SimObject *getSlave(address_type addr);
    void sendRequest(SimObject *sender, address_type addr, ReqResHandler request_handler);
    void sendResponse(SimObject *sender, SimObject *receiver, ReqResHandler response_handler);
    void arbitrate(Event &e);
};
