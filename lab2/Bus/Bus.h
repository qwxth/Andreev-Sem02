// Bus.h
#ifndef BUS_H
#define BUS_H

#include <iostream>

class Bus {
 private:
    char* color;
    char* carBrand;
    char* madeDate;
    double price;

 public:
    Bus();
    Bus(const char* color, const char* carBrand, const char* madeDate, double price);
    Bus(const Bus& other);
    ~Bus();

    Bus& operator=(const Bus& other);
    bool operator<(const Bus& other) const;
    bool operator==(const Bus& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Bus& bus);
    friend std::istream& operator>>(std::istream& is, Bus& bus);

    static void readFromFile(const char* filename, Bus*& Buses, int& size);
    static void writeToFile(const char* filename, const Bus* Buses, int size);
    static void sortBuses(Bus* Buses, int size);
    static void addBus(Bus*& Buses, int& size, const Bus& newBus);
    static void removeBus(Bus*& Buses, int& size, int index);
    static void editBus(Bus& bus);
    static void displayBus(const Bus* Buses, int size);

 private:
    void copyFrom(const Bus& other);
    void cleanup();
};

#endif  // BUS_H
