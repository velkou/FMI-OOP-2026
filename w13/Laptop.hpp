#pragma once
#include "Device.hpp"

class Laptop : public Device {
public:
    ///rule of zero
    Laptop(const char* make, int mHz);

    void print() const override;
    int getPerformance() const override;
    Device* clone() const override;

private:
    int mHz;
};



