#include <iostream>
#include "Car.hpp"
#include "Device.hpp"
#include "Laptop.hpp"
#include "Inventory.hpp"
int main()
{
    Inventory shop;

    Laptop l1("Asus",2400);
    Car c("Toyota",90,2000);
    Laptop l2("Lenovo",3200);

    shop.addDevice(l1);
    shop.addDevice(c);
    shop.addDevice(l2);

    std::cout << "--- All devices ---" << std::endl;
    shop.printInfo();

    std::cout << std::endl;
    std::cout << "Is sorted by performance? "
              << (shop.isSorted() ? "Yes" : "No") << std::endl;

    Inventory sortedShop;
    sortedShop.addDevice(c);
    sortedShop.addDevice(l1);
    sortedShop.addDevice(l2);

    std::cout << std::endl;
    std::cout << "Is sortedShop sorted by performance? "
              << (sortedShop.isSorted() ? "Yes" : "No") << std::endl;

}