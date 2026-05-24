#include "Table.hpp"
#include <iostream>

Table::Table(unsigned height, unsigned width, unsigned len, unsigned quan, TableType type) :
Furniture(height,width,len,quan), type(type) {}

void Table::printInfo() const
{
    std::cout << "Table with: "
              << "measurements: " << height << "x" << width << "x" << length
              << "; quantity: " << quantity;

    if (type == TableType::COFFEE)
        std::cout << "; type: Coffee table";
    else
        std::cout << "; type: Kitchen table";

    std::cout << "; price: " << getPrice() << std::endl;

}

unsigned Table::getPrice() const { return width * length * 15; }

Furniture* Table::clone() const { return new Table(*this); }
