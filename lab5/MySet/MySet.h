#ifndef MYSET_H
#define MYSET_H

#include "../MyVector/MyVector.h"
#include <algorithm>

class MySet : public MyVector<char*> {
public:
    MySet(size_t initialSize = 1);
    MySet(const char* str);
    MySet(const MySet& other);

    bool isElement(const char* element) const;
    void addElement(const char* element);
    void deleteElement(const char* element);

    MySet& operator+=(const MySet& other);
    MySet& operator-=(const MySet& other);
    MySet& operator*=(const MySet& other);
};

MySet operator+(const MySet& a, const MySet& b);
MySet operator-(const MySet& a, const MySet& b);
MySet operator*(const MySet& a, const MySet& b);
bool operator==(const MySet& a, const MySet& b);
std::ostream& operator<<(std::ostream& os, const MySet& set);

#endif // MYSET_H
