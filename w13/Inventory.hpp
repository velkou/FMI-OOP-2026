#pragma once
#include "Device.hpp"
class Inventory {
public:
    Inventory() = default;
    Inventory(const Inventory& other);
    ~Inventory();
    Inventory& operator=(const Inventory& other);


    void printInfo() const;
    bool isSorted() const;
    bool addDevice(const Device& device);

private:
    void clear();
    void copyFrom(const Inventory& other);

private:
    Device* inventory[100];
    unsigned size = 0;
};



