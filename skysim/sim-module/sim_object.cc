#include "sim-module/sim_object.hh"

std::atomic<SimObject::id_type> SimObject::numOfSimObjects{0};

std::ostream& operator<<(std::ostream& os, const SimObject::data_type& obj)
{
    char buffer[6];
    buffer[5] = '\0';
    for(size_t j = 0; j < obj.len; ++j) {
        sprintf(buffer, "0x%02X ", obj.data[j]);
        os << buffer;
    }
    return os;
}
