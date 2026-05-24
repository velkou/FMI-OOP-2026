#pragma once
#include "Furniture.hpp"

enum ChairType
{
    WOODEN,
    METAL,
    PLASTIC
};

class Chair : public Furniture {
public:
    Chair(unsigned height, unsigned width, unsigned len, unsigned quan, ChairType type);

    void printInfo() const override;
    unsigned getPrice() const override;
    Furniture* clone() const override;
private:
    ChairType type;
};
