#pragma once

#include "sim-module/channel.hh"
#include "sim-module/fifo_if.hh"
#define MAX_BUF_SIZE 1<<20

template<typename T, size_t buf_size=MAX_BUF_SIZE>
class FIFO: public Channel, public FIFOReadIF<T>, public FIFOWriteIF<T> {
private:
	std::array<T, buf_size> buf;
	int read_begin, write_begin, n_readable, n_writable;
	int n_read, n_written;
	void update() final {
		read_begin += n_read;
		if((size_t)read_begin >= buf_size)
			read_begin -= buf_size;
		write_begin += n_written;
		if((size_t)write_begin >= buf_size)
			write_begin -= buf_size;
		n_readable += n_written - n_read;
		n_writable += n_read - n_written;
		n_read = n_written = 0;
		assert(0 <= read_begin and (size_t)read_begin < buf_size);
		assert(0 <= write_begin and (size_t)write_begin < buf_size);
		assert(0 <= n_readable and (size_t)n_readable <= buf_size);
		assert(0 <= n_writable and (size_t)n_writable <= buf_size);
	}
public:
	FIFO(EventQueue &eq, const std::string &name): Channel{eq, name}
		, read_begin{0}, write_begin{0}, n_readable{0}, n_writable{buf_size}
		, n_read{0}, n_written{0} {}
	~FIFO() override = default;

	size_t num_free() final {
		return n_writable - n_written;
	}
	size_t num_available() final {
		return n_readable - n_read;
	}
	T pop() final {
		assert(num_available() > 0);
		int idx = read_begin + n_read;
		if((size_t)idx >= buf_size)
			idx -= buf_size;
		n_read++;
		return buf[idx];
	}
	void push(const T &val) final {
		assert(num_free() > 0);
		int idx = write_begin + n_written;
		if((size_t)idx>=buf_size)
			idx -= buf_size;
		buf[idx] = val;
		n_written++;
	}
};
