#include "FurnitureHouse.hpp"

FurnitureHouse::FurnitureHouse() : furn(nullptr), size(0), capacity(0) {}

FurnitureHouse::FurnitureHouse(const FurnitureHouse& other) : size(other.size), capacity(other.capacity)
{
    furn = new Furniture * [capacity] {};
    for (size_t i = 0; i < size; i++)
    {
        try
        {
            furn[i] = other.furn[i]->clone();
        }
        catch (...)
        {
            for (size_t j = 0; j < i; j++)
            {
                delete furn[j];
            }
            delete[] furn;
            throw;
        }
    }
}

FurnitureHouse& FurnitureHouse::operator=(const FurnitureHouse& other)
{
    if (this == &other) return *this;

    FurnitureHouse temp(other);
    std::swap(furn, temp.furn);
    std::swap(size, temp.size);
    std::swap(capacity, temp.capacity);

    return *this;
}

FurnitureHouse::~FurnitureHouse()
{
    clear();
    size = 0;
}

FurnitureHouse& FurnitureHouse::addFurn(const Furniture* item)
{
    if (!item)  throw std::invalid_argument("Cannot add nullptr to Furniture house");

    if (size == capacity) resize();

    furn[size] = item->clone();
    size++;

    return *this;
}

FurnitureHouse& FurnitureHouse::removeFurn(int id)
{
    int indexToRemove = -1;
    for (int i = 0; i < size; i++)
    {
        if (furn[i]->getId() == id)
        {
            indexToRemove = i;
            break;
        }
    }

    if (indexToRemove == -1) throw std::invalid_argument("No such item with chosen ID exists");

    delete furn[indexToRemove];

    for (size_t i = indexToRemove; i < size - 1; i++)
    {
        furn[i] = furn[i + 1];
    }
    furn[size - 1] = nullptr;
    size--;

    return *this;
}

void FurnitureHouse::print() const
{
    for (size_t i = 0; i < size; i++)
    {
        furn[i]->printInfo();
    }
}

Furniture& FurnitureHouse::operator[](size_t index)
{
    return *furn[index];
}

const Furniture& FurnitureHouse::operator[](size_t index) const
{
    return *furn[index];
}

Furniture& FurnitureHouse::getMostExpensive() const
{
    if (size == 0) throw std::runtime_error("Warehouse is empty!");

    int mostExp = 0;
    for (int i = 1; i < size; i++)
    {
        if (furn[i]->getPrice() > furn[mostExp]->getPrice())
        {
            mostExp = i;
        }
    }
    return *furn[mostExp];
}

void FurnitureHouse::clear()
{
    for (size_t i = 0; i < size; i++)
    {
        delete furn[i];
    }
    delete[] furn;
}

void FurnitureHouse::resize()
{
    capacity = (capacity == 0) ? 2 : capacity * 2;
    Furniture** temp = new Furniture * [capacity];
    for (size_t i = 0; i < size;i++)
    {
        temp[i] = furn[i];
    }
    delete[] furn;
    furn = temp;
}
