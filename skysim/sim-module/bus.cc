#include "sim-module/bus.hh"

void Bus::addMaster(SimObject *obj) {
	masters.push_back(obj);
	master_request_queue.emplace(obj, std::queue<std::function<void(Event &)>>{});
}
void Bus::addSlave(SimObject *obj, std::pair<address_type, size_type> seg) {
	slaves.push_back(obj);
	segments.push_back(std::move(seg));
}

SimObject *Bus::getSlave(address_type addr) {
	for(unsigned i=0; i<segments.size(); i++) {
		if(addr >= segments[i].first && addr-segments[i].first < segments[i].second)
			return slaves[i];
	}
	return nullptr;
}

void Bus::sendRequest(SimObject *sender, address_type addr, ReqResHandler request_handler) {
	assert(master_request_queue.find(sender) != master_request_queue.end());
	// Push request_handler to request queue
	master_request_queue[sender].emplace([=](Event &e){
		SimObject *receiver = getSlave(addr);
		if (receiver == nullptr) {
			std::fprintf(stderr, "Send to wrong address: 0x%x from %s\n", addr, sender->name.c_str());
		} else {
			request_handler(sender, receiver, e);
		}
	});
	if (number_of_events == 0) {
		scheduleEvent(ARBITRATION_DELAY, METHOD_AS_EVENT_HANDLER(Bus::arbitrate), name+" request arbitration");
	}
	++number_of_events;
}
void Bus::sendResponse(SimObject *sender, SimObject *receiver, ReqResHandler response_handler) {
	scheduleEvent(1, [=](Event &e){
		response_handler(sender, receiver, e);
	}, name+" pass response");
}


void Bus::arbitrate(Event &e) {
	unsigned current_winner = winner;
	while (current_winner < masters.size() && master_request_queue[masters[current_winner]].empty()) {
		current_winner++;
	}
	if (current_winner == masters.size()) {
		current_winner = 0;
		while (current_winner < winner && master_request_queue[masters[current_winner]].empty()) {
			current_winner++;
		}
	}
	assert(!master_request_queue[masters[current_winner]].empty());
	winner = (current_winner + 1) % masters.size();
	SimObject *master = masters[current_winner];
	// Call to request_handler
	master_request_queue[master].front()(e);
	master_request_queue[master].pop();
	--number_of_events;
	if (number_of_events > 0) {
		scheduleEvent(ARBITRATION_DELAY, e.event_handler, name+" request arbitration finished");
	}
}
