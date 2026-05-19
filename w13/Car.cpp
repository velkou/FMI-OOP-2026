//
// Created by Velin Asparuhov on 19.05.26.
//

#include "Car.hpp"
#include <iostream>

Car::Car(const char* make, int kW, int cm3) : Device(make), kW(kW), cm3(cm3) {}

void Car::print() const
{
    Device::print();
    std::cout << kW << " " << cm3 << std::endl;
}

int Car::getPerformance() const { return kW; }

Device* Car::clone() const { return new Car(*this); }
