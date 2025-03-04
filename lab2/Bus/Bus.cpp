#include "Bus.h"

#include <algorithm>
#include <cstring>
#include <fstream>

Bus::Bus() : color(nullptr), carBrand(nullptr), madeDate(nullptr), price(0.0) {
}

Bus::Bus(const char* color, const char* carBrand, const char* madeDate, double price) : price(price) {
    this->color = new char[strlen(color) + 1];
    strcpy(this->color, color);
    this->carBrand = new char[strlen(carBrand) + 1];
    strcpy(this->carBrand, carBrand);
    this->madeDate = new char[strlen(madeDate) + 1];
    strcpy(this->madeDate, madeDate);
}

Bus::Bus(const Bus& other) {
    copyFrom(other);
}

Bus::~Bus() {
    cleanup();
}

Bus& Bus::operator=(const Bus& other) {
    if (this != &other) {
        cleanup();
        copyFrom(other);
    }
    return *this;
}

bool Bus::operator<(const Bus& other) const {
    return strcmp(color, other.color) < 0;
}

bool Bus::operator==(const Bus& other) const {
    return strcmp(color, other.color) == 0;
}

std::ostream& operator<<(std::ostream& os, const Bus& bus) {
    os << bus.color << " " << bus.carBrand << " " << bus.madeDate << " " << bus.price;
    return os;
}

std::istream& operator>>(std::istream& is, Bus& bus) {
    char buffer[256];
    is >> buffer;
    delete[] bus.color;
    bus.color = new char[strlen(buffer) + 1];
    strcpy(bus.color, buffer);

    is >> buffer;
    delete[] bus.carBrand;
    bus.carBrand = new char[strlen(buffer) + 1];
    strcpy(bus.carBrand, buffer);

    is >> buffer;
    delete[] bus.madeDate;
    bus.madeDate = new char[strlen(buffer) + 1];
    strcpy(bus.madeDate, buffer);

    is >> bus.price;
    return is;
}

void Bus::readFromFile(const char* filename, Bus*& buses, int& size) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "не удалось открыть файл " << filename << " для чтения" << std::endl;
        return;
    }

    if (!(file >> size)) {
        std::cerr << "ошибка при чтении размера массива из файла" << std::endl;
        file.close();
        return;
    }

    delete[] buses;
    buses = new Bus[size];

    file.ignore();

    for (int i = 0; i < size; ++i) {
        char colorBuf[256], brandBuf[256], dateBuf[256];
        double priceBuf;

        if (!(file >> colorBuf >> brandBuf >> dateBuf >> priceBuf)) {
            std::cerr << "ошибка при чтении данных автобуса #" << i+1 << std::endl;
            continue;
        }

        delete[] buses[i].color;
        delete[] buses[i].carBrand;
        delete[] buses[i].madeDate;

        buses[i].color = new char[strlen(colorBuf) + 1];
        strcpy(buses[i].color, colorBuf);

        buses[i].carBrand = new char[strlen(brandBuf) + 1];
        strcpy(buses[i].carBrand, brandBuf);

        buses[i].madeDate = new char[strlen(dateBuf) + 1];
        strcpy(buses[i].madeDate, dateBuf);

        buses[i].price = priceBuf;
    }

    file.close();
    std::cout << "успешно прочитано " << size << " автобусов из файла " << filename << std::endl;
}
void Bus::writeToFile(const char* filename, const Bus* buses, int size) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "не удалось открыть файл для записи." << std::endl;
        return;
    }

    file << size << std::endl;
    for (int i = 0; i < size; ++i) {
        file << buses[i] << std::endl;
    }

    file.close();
}

void Bus::sortBuses(Bus* buses, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (buses[j + 1] < buses[j]) {
                Bus temp = buses[j];
                buses[j] = buses[j + 1];
                buses[j + 1] = temp;
            }
        }
    }
}

void Bus::addBus(Bus*& buses, int& size, const Bus& newBus) {
    Bus* newArray = new Bus[size + 1];
    for (int i = 0; i < size; ++i) {
        newArray[i] = buses[i];
    }
    newArray[size] = newBus;
    delete[] buses;
    buses = newArray;
    ++size;
}

void Bus::removeBus(Bus*& buses, int& size, int index) {
    if (index < 0 || index >= size) {
        std::cerr << "неверный индекс для удаления" << std::endl;
        return;
    }

    Bus* newArray = new Bus[size - 1];
    int j = 0;
    for (int i = 0; i < size; ++i) {
        if (i != index) {
            newArray[j++] = buses[i];
        }
    }
    delete[] buses;
    buses = newArray;
    --size;
}

void Bus::editBus(Bus& bus) {
    std::cout << "введите новые данные для автобуса:" << std::endl;
    std::cin >> bus;
}

void Bus::displayBus(const Bus* buses, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << buses[i] << std::endl;
    }
}

void Bus::copyFrom(const Bus& other) {
    color = new char[strlen(other.color) + 1];
    strcpy(color, other.color);
    carBrand = new char[strlen(other.carBrand) + 1];
    strcpy(carBrand, other.carBrand);
    madeDate = new char[strlen(other.madeDate) + 1];
    strcpy(madeDate, other.madeDate);
    price = other.price;
}

void Bus::cleanup() {
    delete[] color;
    delete[] carBrand;
    delete[] madeDate;
    color = nullptr;
    carBrand = nullptr;
    madeDate = nullptr;
}
