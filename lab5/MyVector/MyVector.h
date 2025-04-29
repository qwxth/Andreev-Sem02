#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <algorithm>
#include <cstring>
#include <stdexcept>

template <typename T = int>
class MyVector {
protected:
    T* pdata;
    size_t size;
    size_t maxSize;

    void resize(size_t newsize);

public:
    MyVector(size_t initialSize = 1);
    MyVector(const T& firstElement);
    MyVector(const MyVector& other);
    virtual ~MyVector();

    MyVector& operator=(const MyVector& other);
    virtual void addElement(const T& element);
    void deleteElement(size_t index);
    int find(const T& element) const;
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    void sort();
    size_t getSize() const;
    size_t getMaxSize() const;
};

template<>
void MyVector<int>::addElement(const int& element);

template<>
class MyVector<char*> {
protected:
    char** pdata;
    size_t size;
    size_t maxSize;

    void resize(size_t newsize);

public:
    MyVector(const char* str);
    MyVector(size_t initialSize = 1);
    MyVector(const MyVector& other);
    ~MyVector();

    MyVector& operator=(const MyVector& other);
    void addElement(const char* element);
    void deleteElement(size_t index);
    int find(const char* element) const;
    char* operator[](size_t index);
    const char* operator[](size_t index) const;
    void sort();
    size_t getSize() const;
    size_t getMaxSize() const;
};

std::ostream& operator<<(std::ostream& os, const MyVector<int>& vec);
std::ostream& operator<<(std::ostream& os, const MyVector<char*>& vec);

#endif // MYVECTOR_H
