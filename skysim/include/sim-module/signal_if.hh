#pragma once

#include "sim-module/if_base.hh"

template<typename T>
class SignalReadIF : public IFBase {
public:
	SignalReadIF() = default;
	~SignalReadIF() = default;
	virtual T read() const = 0;
};

template<typename T>
class SignalWriteIF : public IFBase {
public:
	SignalWriteIF() = default;
	~SignalWriteIF() = default;
	virtual void write(const T &) = 0;
	virtual T read_new() const = 0;
};
