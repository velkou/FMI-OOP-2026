#include "Bed.hpp"
#include <iostream>

Bed::Bed(unsigned height, unsigned width, unsigned len, unsigned quan) :
Furniture(height,width,len,quan) {}

void Bed::printInfo() const
{
    std::cout << "Bed with: "
              << "measurements: " << height << "x" << width << "x" << length
              << "; quantity: " << quantity;

    std::cout << "; price: " << getPrice() << std::endl;
}

unsigned Bed::getPrice() const { return length * height * 22; }

Furniture* Bed::clone() const { return  new Bed(*this); }
