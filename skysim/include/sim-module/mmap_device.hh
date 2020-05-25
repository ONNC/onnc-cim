#pragma once
#include "sim-module/sim_object.hh"
#include "sim-module/bus.hh"

class MMapDevice: public SimObject {
public:
    MMapDevice(EventQueue &eq, std::string name)
      : SimObject{eq, std::move(name)} {}
    ~MMapDevice() override = default;

    // register programming interface
    virtual reg_type regRead(SimObject* sender, address_type addr, transaction_id_type trans_id) = 0;
    virtual void regWrite(SimObject* sender, address_type addr, reg_type data) = 0;
};
