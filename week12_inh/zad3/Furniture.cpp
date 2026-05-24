#include "Furniture.hpp"
int Furniture:: idStep = 1; //TODO vij dali moje da stoi idStep = 1 v .hpp

Furniture::Furniture(unsigned height, unsigned width, unsigned len, unsigned quan) :
height(height), width(width), length(len), quantity(quan)
{
    id = idStep++;
}

