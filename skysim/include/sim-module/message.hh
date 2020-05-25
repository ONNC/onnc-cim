#pragma once

#ifdef LOG
	#define writelog(...) printf(__VA_ARGS__)
#else
	#define writelog(...) (void)0
#endif

struct Message {
    virtual ~Message() = default;
};
