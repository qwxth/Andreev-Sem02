#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <algorithm>
#include <cstring>

template <typename T = int>
class MyVector {
protected:
    T* pdata;
    size_t size;
    size_t maxSize;

    void resize(size_t newsize) {
        if(newsize < 1) newsize = 1;
        T* newData = new T[newsize];
        std::copy(pdata, pdata + size, newData);
        delete[] pdata;
        pdata = newData;
        maxSize = newsize;
    }

public:
    MyVector(size_t initialSize = 1) : size(0), maxSize(initialSize) {
        pdata = new T[maxSize];
    }

    MyVector(const T& firstElement) : size(1), maxSize(1) {
        pdata = new T[1];
        pdata[0] = firstElement;
    }

    MyVector(const MyVector& other) : size(other.size), maxSize(other.maxSize) {
        pdata = new T[maxSize];
        std::copy(other.pdata, other.pdata + size, pdata);
    }

    virtual ~MyVector() {
        delete[] pdata;
    }

    MyVector& operator=(const MyVector& other) {
        if(this == &other) return *this;
        delete[] pdata;
        size = other.size;
        maxSize = other.maxSize;
        pdata = new T[maxSize];
        std::copy(other.pdata, other.pdata + size, pdata);
        return *this;
    }

    virtual void addElement(const T& element) {
        if(size >= maxSize) resize(maxSize * 2);
        pdata[size++] = element;
    }

    void deleteElement(size_t index) {
        if(index >= size) return;
        for(size_t i = index; i < size - 1; ++i) {
            pdata[i] = pdata[i + 1];
        }
        size--;
        if(size < maxSize / 4 && maxSize > 1) resize(maxSize / 2);
    }

    int find(const T& element) const {
        for(size_t i = 0; i < size; ++i) {
            if(pdata[i] == element) return i;
        }
        return -1;
    }

    T& operator[](size_t index) {
        if(index >= size) throw std::out_of_range("Index out of range");
        return pdata[index];
    }

    const T& operator[](size_t index) const {
        if(index >= size) throw std::out_of_range("Index out of range");
        return pdata[index];
    }

    void sort() {
        std::sort(pdata, pdata + size);
    }

    size_t getSize() const { return size; }
    size_t getMaxSize() const { return maxSize; }
};

template<>
void MyVector<int>::addElement(const int& element) {
    if(size >= maxSize) resize(maxSize * 2);
    pdata[size++] = element;
}

template<>
class MyVector<char*> {
protected:
    char** pdata;
    size_t size;
    size_t maxSize;

    void resize(size_t newsize) {
        if(newsize < 1) newsize = 1;
        char** newData = new char*[newsize];
        std::copy(pdata, pdata + size, newData);
        delete[] pdata;
        pdata = newData;
        maxSize = newsize;
    }

public:
    MyVector(const char* str) : size(1), maxSize(1) {
        pdata = new char*[1];
        pdata[0] = new char[strlen(str) + 1];
        strcpy(pdata[0], str);
    }

    MyVector(size_t initialSize = 1) : size(0), maxSize(initialSize) {
        pdata = new char*[maxSize];
    }

    MyVector(const MyVector& other) : size(other.size), maxSize(other.maxSize) {
        pdata = new char*[maxSize];
        for(size_t i = 0; i < size; ++i) {
            pdata[i] = new char[strlen(other.pdata[i]) + 1];
            strcpy(pdata[i], other.pdata[i]);
        }
    }

    ~MyVector() {
        for(size_t i = 0; i < size; ++i) {
            delete[] pdata[i];
        }
        delete[] pdata;
    }

    MyVector& operator=(const MyVector& other) {
        if(this == &other) return *this;

        for(size_t i = 0; i < size; ++i) {
            delete[] pdata[i];
        }
        delete[] pdata;

        size = other.size;
        maxSize = other.maxSize;
        pdata = new char*[maxSize];

        for(size_t i = 0; i < size; ++i) {
            pdata[i] = new char[strlen(other.pdata[i]) + 1];
            strcpy(pdata[i], other.pdata[i]);
        }

        return *this;
    }

    void addElement(const char* element) {
        if(size >= maxSize) resize(maxSize * 2);
        pdata[size] = new char[strlen(element) + 1];
        strcpy(pdata[size], element);
        size++;
    }

    void deleteElement(size_t index) {
        if(index >= size) return;

        delete[] pdata[index];

        for(size_t i = index; i < size - 1; ++i) {
            pdata[i] = pdata[i + 1];
        }

        size--;
        if(size < maxSize / 4 && maxSize > 1) resize(maxSize / 2);
    }

    int find(const char* element) const {
        for(size_t i = 0; i < size; ++i) {
            if(strcmp(pdata[i], element) == 0) return i;
        }
        return -1;
    }

    char* operator[](size_t index) {
        if(index >= size) throw std::out_of_range("Index out of range");
        return pdata[index];
    }

    const char* operator[](size_t index) const {
        if(index >= size) throw std::out_of_range("Index out of range");
        return pdata[index];
    }

    void sort() {
        std::sort(pdata, pdata + size, [](const char* a, const char* b) {
            return strcmp(a, b) < 0;
        });
    }

    size_t getSize() const { return size; }
    size_t getMaxSize() const { return maxSize; }
};

std::ostream& operator<<(std::ostream& os, const MyVector<int>& vec) {
    os << "\n{";
    for(size_t i = 0; i < vec.getSize(); ++i) {
        if(i > 0) os << ", ";
        os << vec[i];
    }
    return os << "}\n";
}

std::ostream& operator<<(std::ostream& os, const MyVector<char*>& vec) {
    os << "\n{";
    for(size_t i = 0; i < vec.getSize(); ++i) {
        if(i > 0) os << ", ";
        os << vec[i];
    }
    return os << "}\n";
}

#endif // MYVECTOR_H
