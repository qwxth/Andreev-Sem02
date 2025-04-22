#ifndef MYSET_H
#define MYSET_H

#include "../MyVector/MyVector.h"
#include <algorithm>

class MySet : public MyVector<char*> {
public:
    MySet(size_t initialSize = 1) : MyVector<char*>(initialSize) {}
    MySet(const char* str) : MyVector<char*>(str) {}
    MySet(const MySet& other) : MyVector<char*>(other) {}

    bool isElement(const char* element) const {
        return find(element) != -1;
    }

    void addElement(const char* element) {
        if (!isElement(element)) {
            MyVector<char*>::addElement(element);
            sort();
        }
    }

    void deleteElement(const char* element) {
        int index = find(element);
        if (index != -1) {
            MyVector<char*>::deleteElement(index);
        }
    }

    MySet& operator+=(const MySet& other) {
        for (size_t i = 0; i < other.getSize(); ++i) {
            addElement(other[i]);
        }
        return *this;
    }

    MySet& operator-=(const MySet& other) {
        for (size_t i = 0; i < other.getSize(); ++i) {
            deleteElement(other[i]);
        }
        return *this;
    }

    MySet& operator*=(const MySet& other) {
        for (size_t i = 0; i < getSize(); ) {
            if (!other.isElement((*this)[i])) {
                deleteElement((*this)[i]);
            } else {
                ++i;
            }
        }
        return *this;
    }
};

inline MySet operator+(const MySet& a, const MySet& b) {
    MySet result = a;
    for (size_t i = 0; i < b.getSize(); ++i) {
        result.addElement(b[i]);
    }
    return result;
}

inline MySet operator-(const MySet& a, const MySet& b) {
    MySet result = a;
    for (size_t i = 0; i < b.getSize(); ++i) {
        result.deleteElement(b[i]);
    }
    return result;
}

inline MySet operator*(const MySet& a, const MySet& b) {
    MySet result;
    for (size_t i = 0; i < a.getSize(); ++i) {
        if (b.isElement(a[i])) {
            result.addElement(a[i]);
        }
    }
    return result;
}

inline bool operator==(const MySet& a, const MySet& b) {
    if (a.getSize() != b.getSize()) return false;
    for (size_t i = 0; i < a.getSize(); ++i) {
        if (!b.isElement(a[i])) return false;
    }
    return true;
}

inline std::ostream& operator<<(std::ostream& os, const MySet& set) {
    return os << static_cast<const MyVector<char*>&>(set);
}

#define MaxSize 100

#endif // MYSET_H
