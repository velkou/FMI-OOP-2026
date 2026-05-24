#include "Chair.hpp"
#include <iostream>

Chair::Chair(unsigned height, unsigned width, unsigned len, unsigned quan, ChairType type) :
Furniture(height,width,len,quan), type(type) {}

void Chair::printInfo() const
{
    std::cout << "Chair with: "
               << "measurements: " << height << "x" << width << "x" << length
               << "; quantity: " << quantity;

    if (type == ChairType::WOODEN)
        std::cout << "; type: Wooden chair";
    else if (type == ChairType::METAL)
        std::cout << "; type: Metal chair";
    else
        std::cout << "; type: Plastic chair";

    std::cout << "; price: " << getPrice() << std::endl;

}

unsigned Chair::getPrice() const { return height * width * 9; }

Furniture* Chair::clone() const { return  new Chair(*this); }
