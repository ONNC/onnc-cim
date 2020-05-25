#pragma once

#include "sim-module/channel.hh"
#include "sim-module/signal_if.hh"

template<typename T>
class Signal : public Channel, public SignalReadIF<T>, public SignalWriteIF<T> {
	T cur_val, new_val;
	void update() final {
		cur_val = new_val;
	}
public:
	Signal(EventQueue &eq, const std::string &name): Channel{eq, name} {}
	~Signal() override = default;

	T read() const final {
		return cur_val;
	}
	T read_new() const final {
		return new_val;
	}
	void write(const T &val) {
		new_val = val;
	}
};
