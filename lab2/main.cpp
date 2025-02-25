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
    std::cout << "\nГлавное меню:\n"
              << "1. Работа с планетами\n"
              << "2. Работа с автобусами\n"
              << "3. Запуск тестов\n"
              << "0. Выход из программы\n"
              << "Выберите действие: ";
}

void displaySubMenu(const std::string& type) {
    std::cout << "\nМеню " << type << ":\n"
              << "1. Чтение БД из файла\n"
              << "2. Запись БД в файл\n"
              << "3. Сортировка БД\n"
              << "4. Добавление нового элемента\n"
              << "5. Удаление элемента\n"
              << "6. Редактирование элемента\n"
              << "7. Вывод БД на экран\n"
              << "0. Возврат в главное меню\n"
              << "Выберите действие: ";
}

void runTests() {
    std::cout << "\n--- Запуск тестов ---\n";

    std::cout << "\nТест 1: Создание и вывод планет\n";
    Planet earth("Earth", 12742, 1, true);
    Planet mars("Mars", 6779, 2, false);
    std::cout << "Earth: " << earth << std::endl;
    std::cout << "Mars: " << mars << std::endl;

    std::cout << "\nТест 2: Сортировка планет\n";
    Planet* planets = new Planet[2];
    planets[0] = mars;
    planets[1] = earth;
    std::cout << "До сортировки:\n";
    Planet::displayPlanets(planets, 2);
    Planet::sortPlanets(planets, 2);
    std::cout << "После сортировки:\n";
    Planet::displayPlanets(planets, 2);
    delete[] planets;

    std::cout << "\nТест 3: Создание и вывод автобусов\n";
    Bus bus1("blue", "Mersedes", "12.05.2000", 5000000.0);
    Bus bus2("red", "Kamaz", "23.01.2005", 60000000.0);
    std::cout << "автобус 1: " << bus1 << std::endl;
    std::cout << "автобус 2: " << bus2 << std::endl;

    std::cout << "\nТест 4: Сортировка автобусов\n";
    Bus* bus = new Bus[2];
    bus[0] = bus2;
    bus[1] = bus1;
    std::cout << "До сортировки:\n";
    Bus::displayBus(bus, 2);
    Bus::sortBuses(bus, 2);
    std::cout << "После сортировки:\n";
    Bus::displayBus(bus, 2);
    delete[] bus;

    std::cout << "\nТест 5: Добавление и удаление автобусов\n";
    Bus* busDB = nullptr;
    int size = 0;
    Bus::addBus(busDB, size, bus1);
    Bus::addBus(busDB, size, bus2);
    std::cout << "После добавления:\n";
    Bus::displayBus(busDB, size);
    Bus::removeBus(busDB, size, 0);
    std::cout << "После удаления:\n";
    Bus::displayBus(busDB, size);
    delete[] busDB;

    std::cout << "\n--- Тесты завершены ---\n";
}

template<typename T>
void runDatabase(const std::string& type) {
    T* items = nullptr;
    int size = 0;
    int choice;
    char filename[256];

    do {
        displaySubMenu(type);
        std::cin >> choice;
        clearInputBuffer();


        switch (choice) {
            case 1:
                std::cout << "Введите имя файла для чтения: ";
                std::cin >> filename;
                T::readFromFile(filename, items, size);
                break;
            case 2:
                std::cout << "Введите имя файла для записи: ";
                std::cin >> filename;
                T::writeToFile(filename, items, size);
                break;
            case 3:
                if constexpr (std::is_same_v<T, Planet>) {
                    T::sortPlanets(items, size);
                } else {
                    T::sortBuses(items, size);
                }
                std::cout << "БД отсортирована.\n";
                break;
            case 4: {
                T newItem;
                std::cout << "Введите данные нового элемента:\n";
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
                std::cout << "Введите индекс элемента для удаления: ";
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
                std::cout << "Введите индекс элемента для редактирования: ";
                std::cin >> index;
                if (index >= 0 && index < size) {
                    if constexpr (std::is_same_v<T, Planet>) {
                        T::editPlanet(items[index]);
                    } else {
                        T::editBus(items[index]);
                    }
                } else {
                    std::cout << "Неверный индекс.\n";
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
                std::cout << "Возврат в главное меню.\n";
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    delete[] items;
}

int main() {
    int choice;

    do {
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
                std::cout << "Выход из программы.\n";
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}
