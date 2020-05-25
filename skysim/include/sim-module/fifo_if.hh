#pragma once

#include "sim-module/if_base.hh"

template<typename T>
class FIFOReadIF : public IFBase {
public:
	FIFOReadIF() = default;
	~FIFOReadIF() = default;
	virtual T pop() = 0;
	virtual size_t num_available() = 0;
};

template<typename T>
class FIFOWriteIF : public IFBase {
public:
	FIFOWriteIF() = default;
	~FIFOWriteIF() = default;
	virtual void push(const T &) = 0;
	virtual size_t num_free() = 0;
};
