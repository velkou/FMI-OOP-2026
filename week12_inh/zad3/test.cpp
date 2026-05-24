#include <iostream>
#include "FurnitureHouse.hpp"
#include "Chair.hpp"
#include "Table.hpp"
#include "Bed.hpp"

int main() {
    try {
        FurnitureHouse house;

        std::cout << "=== 1. Добавяне на мебели (Полиморфизъм) ===" << std::endl;
        
        Chair chair1(90, 45, 45, 4, ChairType::WOODEN);
        Table table1(75, 90, 120, 1, TableType::KITCHEN);
        Bed bed1(60, 160, 200, 2);

        house.addFurn(&chair1);
        house.addFurn(&table1);
        house.addFurn(&bed1);

        house.print();
        std::cout << std::endl;

        std::cout << "=== 2. Тест на getMostExpensive ===" << std::endl;
        Furniture& mostExpensive = house.getMostExpensive();
        std::cout << "Най-скъпата мебел в склада е с ID " << mostExpensive.getId() << ": ";
        mostExpensive.printInfo();
        std::cout << std::endl;

        std::cout << "=== 3. Тест на оператор [] ===" << std::endl;
        std::cout << "Мебелта на индекс 0 е: ";
        house[0].printInfo();
        std::cout << std::endl;

        std::cout << "=== 4. Тест на removeFurn (Премахваме Масата с ID 2) ===" << std::endl;
        house.removeFurn(2);
        std::cout << "Съдържание на склада след премахването:" << std::endl;
        house.print();
        std::cout << std::endl;

        std::cout << "=== 5. Тест на Голямата Тройка (Копиращ конструктор) ===" << std::endl;
        FurnitureHouse copyHouse = house;
        std::cout << "Съдържание на КЛОНИРАНИЯ склад (copyHouse):" << std::endl;
        copyHouse.print();
        std::cout << std::endl;

        std::cout << "=== 6. Тест за грешно въведено ID ===" << std::endl;
        house.removeFurn(999); // Трябва да хвърли изключение invalid_argument

    }
    catch (const std::invalid_argument& e) {
        std::cerr << "[Изключение - invalid_argument]: " << e.what() << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "[Изключение - runtime_error]: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Възникна неочаквана грешка!" << std::endl;
    }

    return 0;
}