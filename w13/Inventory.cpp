//
// Created by Velin Asparuhov on 19.05.26.
//

#include "Inventory.hpp"
#include <iostream>

Inventory::Inventory(const Inventory& other)
{
    copyFrom(other);
}

Inventory::~Inventory()
{
    clear();
}

Inventory& Inventory::operator=(const Inventory& other)
{
    if (this == &other) return *this;

    clear();
    copyFrom(other);

    return *this;
}

void Inventory::clear()
{
    for (size_t i = 0; i < size; i++)
    {
        delete inventory[i];
    }
    size = 0;
}

void Inventory::copyFrom(const Inventory& other)
{
    size = other.size;
    for (size_t i = 0; i < size; i++)
    {
        inventory[i] = other.inventory[i]->clone();
    }
}

void Inventory::printInfo() const
{
    for (size_t i = 0; i < size; i++)
    {
        inventory[i]->print();
    }
}

bool Inventory::isSorted() const
{
    if (size <= 1) return true;

    for (size_t i = 0; i < size - 1 ; i++)
    {
        if (inventory[i]->getPerformance() > inventory[i + 1]->getPerformance())
            return false;
    }
    return true;
}

bool Inventory::addDevice(const Device& device)
{
    if (size >= 100) return false;
    inventory[size] = device.clone();
    ++size;
    return true;
}
