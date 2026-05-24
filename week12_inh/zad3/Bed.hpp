#pragma once
#include "Furniture.hpp"

class Bed : public Furniture {
public:
    Bed(unsigned height, unsigned width, unsigned len, unsigned quan);

    void printInfo() const override;
    unsigned getPrice() const override;
    Furniture* clone() const override;
private:
};



