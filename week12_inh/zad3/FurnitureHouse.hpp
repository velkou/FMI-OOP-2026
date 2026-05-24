#pragma once
#include "Furniture.hpp"
#include <iostream>

class FurnitureHouse {
public:
    //big 4
    FurnitureHouse();
    FurnitureHouse(const FurnitureHouse& other);
    FurnitureHouse& operator=(const FurnitureHouse& other);
    ~FurnitureHouse();

    //functionality
    FurnitureHouse& addFurn(const Furniture* item);
    FurnitureHouse& removeFurn(int id);
    void print() const;
    Furniture& operator[](size_t index);
    const Furniture& operator[](size_t index) const;
    Furniture& getMostExpensive() const;

private:
    void clear();
    void resize();
private:
    Furniture** furn;
    size_t capacity;
    size_t size;
};
