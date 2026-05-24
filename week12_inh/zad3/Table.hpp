#pragma once
#include "Furniture.hpp"

enum TableType
{
    COFFEE,
    KITCHEN
};

class Table : public Furniture {
public:
    Table(unsigned height, unsigned width, unsigned len, unsigned quan, TableType type);

    void printInfo() const override;
    unsigned getPrice() const override;
    Furniture* clone() const override;
private:
    TableType type;
};
