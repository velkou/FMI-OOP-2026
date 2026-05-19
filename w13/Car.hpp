#pragma once
#include "Device.hpp"

class Car : public Device {
public:
    ///rule of zero
    Car(const char* make, int kW, int cm3);

    void print() const override;
    int getPerformance() const override;
    Device* clone() const override;

private:
    int kW, cm3;
};



