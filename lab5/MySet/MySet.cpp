#include "MySet.h"
#include <cstring>

MySet::MySet(size_t initialSize) : MyVector<char*>(initialSize) {}

MySet::MySet(const char* str) : MyVector<char*>(str) {}

MySet::MySet(const MySet& other) : MyVector<char*>(other) {}

bool MySet::isElement(const char* element) const {
    return find(element) != -1;
}

void MySet::addElement(const char* element) {
    if (!isElement(element)) {
        MyVector<char*>::addElement(element);
        sort();
    }
}

void MySet::deleteElement(const char* element) {
    int index = find(element);
    if (index != -1) {
        MyVector<char*>::deleteElement(index);
    }
}

MySet& MySet::operator+=(const MySet& other) {
    for (size_t i = 0; i < other.getSize(); ++i) {
        addElement(other[i]);
    }
    return *this;
}

MySet& MySet::operator-=(const MySet& other) {
    for (size_t i = 0; i < other.getSize(); ++i) {
        deleteElement(other[i]);
    }
    return *this;
}

MySet& MySet::operator*=(const MySet& other) {
    for (size_t i = 0; i < getSize(); ) {
        if (!other.isElement((*this)[i])) {
            deleteElement((*this)[i]);
        } else {
            ++i;
        }
    }
    return *this;
}

MySet operator+(const MySet& a, const MySet& b) {
    MySet result = a;
    result += b;
    return result;
}

MySet operator-(const MySet& a, const MySet& b) {
    MySet result = a;
    result -= b;
    return result;
}

MySet operator*(const MySet& a, const MySet& b) {
    MySet result;
    for (size_t i = 0; i < a.getSize(); ++i) {
        if (b.isElement(a[i])) {
            result.addElement(a[i]);
        }
    }
    return result;
}

bool operator==(const MySet& a, const MySet& b) {
    if (a.getSize() != b.getSize()) return false;
    for (size_t i = 0; i < a.getSize(); ++i) {
        if (!b.isElement(a[i])) return false;
    }
    return true;
}

std::ostream& operator<<(std::ostream& os, const MySet& set) {
    return os << static_cast<const MyVector<char*>&>(set);
}
