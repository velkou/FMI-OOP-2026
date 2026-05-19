//
// Created by Velin Asparuhov on 19.05.26.
//

#include "Laptop.hpp"
#include <iostream>
//rule of zero
Laptop::Laptop(const char* make, int mHz) : Device(make), mHz(mHz) {}

void Laptop::print() const
{
    Device::print();
    std::cout << mHz << std::endl;
}

int Laptop::getPerformance() const { return mHz; }

Device* Laptop::clone() const { return new Laptop(*this); }
