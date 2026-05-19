//
// Created by Velin Asparuhov on 19.05.26.
//

#include "Device.hpp"
#include <iostream>
#include <stdexcept>

Device::Device(const char* make)
{
    setStr(make);
}

Device::Device(const Device& other)
{
    setStr(other.make);
}

Device::~Device()
{
    clear();
}

Device& Device::operator=(const Device& other)
{
    if (this == &other) return *this;
    setStr(other.make);

    return *this;
}

void Device::print() const
{
    std::cout << make << " ";
}

void Device::setStr(const char* str)
{
    if (!str) throw std::invalid_argument("null");
    char* temp = new char[strlen(str) + 1];
    strcpy(temp,str);
    clear();

    make = temp;
}

void Device::clear()
{
    delete[] make;
    make = nullptr;
}
