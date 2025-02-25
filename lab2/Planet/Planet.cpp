#include "Planet.h"

#include <algorithm>
#include <cstring>
#include <fstream>

Planet::Planet() : name(nullptr), diameter(0), satellites(0), hasLife(false) {
}

Planet::Planet(const char* name, long long diameter, int satellites, bool hasLife) : diameter(diameter), satellites(satellites), hasLife(hasLife) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

Planet::Planet(const Planet& other) : name(nullptr) {
    copyFrom(other);
}

Planet::~Planet() {
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
    if (!name || !other.name)
        return false;
    return strcmp(name, other.name) < 0;
}

bool Planet::operator==(const Planet& other) const {
    if (!name || !other.name)
        return false;
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

    file >> size;
    file.ignore();
    std::cout << "Прочитан размер: " << size << std::endl;

    if (planets != nullptr) {
        delete[] planets;
        planets = nullptr;
    }

    planets = new Planet[size];

    for (int i = 0; i < size; i++) {
        char name[256];
        long long diam;
        int sat;
        int life;

        if (file >> name >> diam >> sat >> life) {
            std::cout << "Попытка создания планеты " << i << ": " << name << " " << diam << " " << sat << " " << life << std::endl;

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
