#include "Planet/Planet.h"
#include "Bus/Bus.h"
#include <iostream>
#include <fstream>
#include <limits>

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void displayMainMenu() {
    std::cout << std::endl << "главное меню:" << std::endl
              << "1. работа с планетами" << std::endl
              << "2. работа с автобусами" << std::endl
              << "3. запуск тестов" << std::endl
              << "0. выход из программы"  << std::endl
              << "выберите действие: ";
}

void displaySubMenu(const std::string& type) {
    std::cout << std::endl << "меню " << type << ":"  << std::endl
              << "1. чтение БД из файла" << std::endl
              << "2. запись БД в файл" << std::endl
              << "3. сортировка БД" << std::endl
              << "4. добавление нового элемента" << std::endl
              << "5. удаление элемента" << std::endl
              << "6. редактирование элемента" << std::endl
              << "7. вывод БД на экран" << std::endl
              << "0. возврат в главное меню" << std::endl
              << "выберите действие: ";
}

void runTests() {
    std::cout << std::endl << "запуск тестов" << std::endl;

    std::cout << std::endl << "тест 1: создание и вывод планет" << std::endl;
    Planet earth("Earth", 12742, 1, true);
    Planet mars("Mars", 6779, 2, false);
    std::cout << "Earth: " << earth << std::endl;
    std::cout << "Mars: " << mars << std::endl;

    std::cout << std::endl << "тест 2: сортировка планет" << std::endl;
    Planet* planets = new Planet[2];
    planets[0] = mars;
    planets[1] = earth;
    std::cout << "до сортировки:" << std::endl;
    Planet::displayPlanets(planets, 2);
    Planet::sortPlanets(planets, 2);
    std::cout << "после сортировки:" << std::endl;
    Planet::displayPlanets(planets, 2);
    delete[] planets;

    std::cout << std::endl << "тест 3: создание и вывод автобусов" << std::endl;
    Bus bus1("blue", "Mersedes", "12.05.2000", 5000000.0);
    Bus bus2("red", "Kamaz", "23.01.2005", 60000000.0);
    std::cout << "автобус 1: " << bus1 << std::endl;
    std::cout << "автобус 2: " << bus2 << std::endl;

    std::cout << std::endl << "тест 4: сортировка автобусов" << std::endl;
    Bus* bus = new Bus[2];
    bus[0] = bus2;
    bus[1] = bus1;
    std::cout << "до сортировки:" << std::endl;
    Bus::displayBus(bus, 2);
    Bus::sortBuses(bus, 2);
    std::cout << "после сортировки:" << std::endl;
    Bus::displayBus(bus, 2);
    delete[] bus;

    std::cout << std::endl << "тест 5: добавление и удаление автобусов" << std::endl;
    Bus* busDB = nullptr;
    int size = 0;
    Bus::addBus(busDB, size, bus1);
    Bus::addBus(busDB, size, bus2);
    std::cout << "после добавления:" << std::endl;
    Bus::displayBus(busDB, size);
    Bus::removeBus(busDB, size, 0);
    std::cout << "после удаления:" << std::endl;
    Bus::displayBus(busDB, size);
    delete[] busDB;

    std::cout << std::endl << "тесты завершены" << std::endl;
}

template<typename T>
void runDatabase(const std::string& type) {
    T* items = nullptr;
    int size = 0;
    int choice = 1;
    char filename[256];

    while (choice != 0){
        displaySubMenu(type);
        std::cin >> choice;
        clearInputBuffer();


        switch (choice) {
            case 1:
                std::cout << "введите имя файла для чтения: ";
                std::cin >> filename;
                T::readFromFile(filename, items, size);
                break;
            case 2:
                std::cout << "введите имя файла для записи: ";
                std::cin >> filename;
                T::writeToFile(filename, items, size);
                break;
            case 3:
                if constexpr (std::is_same_v<T, Planet>) {
                    T::sortPlanets(items, size);
                } else {
                    T::sortBuses(items, size);
                }
                std::cout << "БД отсортирована" << std::endl;
                break;
            case 4: {
                T newItem;
                std::cout << "введите данные нового элемента:" << std::endl;
                std::cin >> newItem;
                if constexpr (std::is_same_v<T, Planet>) {
                    T::addPlanet(items, size, newItem);
                } else {
                    T::addBus(items, size, newItem);
                }
                break;
            }
            case 5: {
                int index;
                std::cout << "введите индекс элемента для удаления: ";
                std::cin >> index;
                if constexpr (std::is_same_v<T, Planet>) {
                    T::removePlanet(items, size, index);
                } else {
                    T::removeBus(items, size, index);
                }
                break;
            }
            case 6: {
                int index;
                std::cout << "введите индекс элемента для редактирования: ";
                std::cin >> index;
                if (index >= 0 && index < size) {
                    if constexpr (std::is_same_v<T, Planet>) {
                        T::editPlanet(items[index]);
                    } else {
                        T::editBus(items[index]);
                    }
                } else {
                    std::cout << "неверный индекс" << std::endl;
                }
                break;
            }
            case 7:
                if constexpr (std::is_same_v<T, Planet>) {
                    T::displayPlanets(items, size);
                } else {
                    T::displayBus(items, size);
                }
                break;
            case 0:
                std::cout << "возврат в главное меню" << std::endl;
                break;
            default:
                std::cout << "введены недопустимые данные"  << std::endl;
        }
    }

    delete[] items;
}

int main() {
    int choice = 1;

    while (choice != 0) {
        displayMainMenu();
        std::cin >> choice;
        clearInputBuffer();

        switch (choice) {
            case 1:
                runDatabase<Planet>("планет");
                break;
            case 2:
                runDatabase<Bus>("автобусов");
                break;
            case 3:
                runTests();
                break;
            case 0:
                std::cout << "выход из программы" << std::endl;
                break;
            default:
                std::cout << "введены недопустимые данные" << std::endl;
        }
    }

    return 0;
}
