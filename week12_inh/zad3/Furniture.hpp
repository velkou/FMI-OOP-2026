#pragma once
class Furniture {
public:
    Furniture(unsigned height, unsigned width, unsigned len, unsigned quan);
    virtual ~Furniture() = default; ///PAK ZABRAVQM VIRTUALNIQ

    virtual unsigned getPrice() const = 0;
    virtual void printInfo() const = 0;
    virtual Furniture* clone() const = 0;
    int getId() const { return id; }
protected:
    static int idStep;
    int id;
    unsigned height;
    unsigned width;
    unsigned length;
    unsigned quantity;
};
