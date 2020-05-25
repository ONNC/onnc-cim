#pragma once

#include "sim-module/sim_object.hh"

class Channel : public SimObject {
protected:
	virtual void update() = 0;
public:
	Channel(EventQueue &eq, const std::string &name) : SimObject{eq, name} {
		eq.add_update([=]() {
			update();
		});
	}
};
