#include "planet.h"
#include <cstring>
#include <algorithm>
#include <fstream>

int Planet::count = 0;

Planet::Planet() : id(++count), name(nullptr), diameter(0), satellites(0), hasLife(false) {
    std::cout << "Создание ID " << id << std::endl;
}

Planet::Planet(const char* name, long long diameter, int satellites, bool hasLife)
    : id(++count), diameter(diameter), satellites(satellites), hasLife(hasLife) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    std::cout << "Создание ID " << id << std::endl;
}

Planet::Planet(const Planet& other) : id(++count), name(nullptr) {
    copyFrom(other);
    std::cout << "Создание ID " << id << " (копирование)" << std::endl;
}

Planet::~Planet() {
    std::cout << "Удаление ID " << id << std::endl;
    cleanup();
}

Planet& Planet::operator=(const Planet& other) {
    if (this != &other) {
        cleanup();
        copyFrom(other);
    }
    return *this;
}

bool Planet::operator<(const Planet& other) const {
    if (!name || !other.name) return false;
    return strcmp(name, other.name) < 0;
}

bool Planet::operator==(const Planet& other) const {
    if (!name || !other.name) return false;
    return strcmp(name, other.name) == 0;
}

std::ostream& operator<<(std::ostream& os, const Planet& planet) {
    os << planet.name << " " << planet.diameter << " " << planet.satellites << " " << planet.hasLife;
    return os;
}

std::istream& operator>>(std::istream& is, Planet& planet) {
    char name[256];
    is >> name;

    delete[] planet.name;
    planet.name = new char[strlen(name) + 1];
    strcpy(planet.name, name);

    is >> planet.diameter >> planet.satellites >> planet.hasLife;
    return is;
}

void Planet::readFromFile(const char* filename, Planet*& planets, int& size) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Не удалось открыть файл для чтения." << std::endl;
        return;
    }

    // Читаем размер
    file >> size;
    file.ignore(); // Пропускаем символ новой строки после размера
    std::cout << "Прочитан размер: " << size << std::endl;

    // Освобождаем старую память
    if (planets != nullptr) {
        delete[] planets;
        planets = nullptr;
    }

    // Выделяем новую память
    planets = new Planet[size];

    // Читаем данные планет
    for (int i = 0; i < size; i++) {
        char name[256];
        long long diam;
        int sat;
        int life;

        // Читаем данные текущей планеты
        if (file >> name >> diam >> sat >> life) {
            std::cout << "Попытка создания планеты " << i << ": "
                      << name << " " << diam << " "
                      << sat << " " << life << std::endl;

            planets[i] = Planet(name, diam, sat, life != 0);
            std::cout << "Планета " << i << " успешно создана" << std::endl;
        } else {
            std::cerr << "Ошибка при чтении планеты " << i << std::endl;
            break;
        }
    }

    file.close();
}

void Planet::writeToFile(const char* filename, const Planet* planets, int size) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Не удалось открыть файл для записи." << std::endl;
        return;
    }

    file << size << std::endl;
    for (int i = 0; i < size; ++i) {
        file << planets[i] << std::endl;
    }

    file.close();
}

void Planet::sortPlanets(Planet* planets, int size) {
    std::sort(planets, planets + size);
}

void Planet::addPlanet(Planet*& planets, int& size, const Planet& newPlanet) {
    Planet* newArray = new Planet[size + 1];
    for (int i = 0; i < size; ++i) {
        newArray[i] = planets[i];
    }
    newArray[size] = newPlanet;
    delete[] planets;
    planets = newArray;
    ++size;
}

void Planet::removePlanet(Planet*& planets, int& size, int index) {
    if (index < 0 || index >= size) {
        std::cerr << "Неверный индекс для удаления." << std::endl;
        return;
    }

Planet* newArray = new Planet[size - 1];
    int j = 0;
    for (int i = 0; i < size; ++i) {
        if (i != index) {
            newArray[j++] = planets[i];
        }
    }
    delete[] planets;
    planets = newArray;
    --size;
}

void Planet::editPlanet(Planet& planet) {
    std::cout << "Введите новые данные для планеты:" << std::endl;
    std::cin >> planet;
}

void Planet::displayPlanets(const Planet* planets, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << planets[i] << std::endl;
    }
}

void Planet::copyFrom(const Planet& other) {
    if (other.name) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    } else {
        name = nullptr;
    }
    diameter = other.diameter;
    satellites = other.satellites;
    hasLife = other.hasLife;
}

void Planet::cleanup() {
    delete[] name;
    name = nullptr;
}
