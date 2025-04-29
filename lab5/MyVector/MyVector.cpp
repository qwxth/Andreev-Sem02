#include "MyVector.h"

template <typename T>
void MyVector<T>::resize(size_t newsize) {
    if(newsize < 1) newsize = 1;
    T* newData = new T[newsize];
    std::copy(pdata, pdata + size, newData);
    delete[] pdata;
    pdata = newData;
    maxSize = newsize;
}

template <typename T>
MyVector<T>::MyVector(size_t initialSize) : size(0), maxSize(initialSize) {
    pdata = new T[maxSize];
}

template <typename T>
MyVector<T>::MyVector(const T& firstElement) : size(1), maxSize(1) {
    pdata = new T[1];
    pdata[0] = firstElement;
}

template <typename T>
MyVector<T>::MyVector(const MyVector& other) : size(other.size), maxSize(other.maxSize) {
    pdata = new T[maxSize];
    std::copy(other.pdata, other.pdata + size, pdata);
}

template <typename T>
MyVector<T>::~MyVector() {
    delete[] pdata;
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& other) {
    if(this == &other) return *this;
    delete[] pdata;
    size = other.size;
    maxSize = other.maxSize;
    pdata = new T[maxSize];
    std::copy(other.pdata, other.pdata + size, pdata);
    return *this;
}

template <typename T>
void MyVector<T>::addElement(const T& element) {
    if(size >= maxSize) resize(maxSize * 2);
    pdata[size++] = element;
}

template <typename T>
void MyVector<T>::deleteElement(size_t index) {
    if(index >= size) return;
    for(size_t i = index; i < size - 1; ++i) {
        pdata[i] = pdata[i + 1];
    }
    size--;
    if(size < maxSize / 4 && maxSize > 1) resize(maxSize / 2);
}

template <typename T>
int MyVector<T>::find(const T& element) const {
    for(size_t i = 0; i < size; ++i) {
        if(pdata[i] == element) return i;
    }
    return -1;
}

template <typename T>
T& MyVector<T>::operator[](size_t index) {
    if(index >= size) throw std::out_of_range("Index out of range");
    return pdata[index];
}

template <typename T>
const T& MyVector<T>::operator[](size_t index) const {
    if(index >= size) throw std::out_of_range("Index out of range");
    return pdata[index];
}

template <typename T>
void MyVector<T>::sort() {
    std::sort(pdata, pdata + size);
}

template <typename T>
size_t MyVector<T>::getSize() const { return size; }

template <typename T>
size_t MyVector<T>::getMaxSize() const { return maxSize; }

template<>
void MyVector<int>::addElement(const int& element) {
    if(size >= maxSize) resize(maxSize * 2);
    pdata[size++] = element;
}

void MyVector<char*>::resize(size_t newsize) {
    if(newsize < 1) newsize = 1;
    char** newData = new char*[newsize];
    std::copy(pdata, pdata + size, newData);
    delete[] pdata;
    pdata = newData;
    maxSize = newsize;
}

MyVector<char*>::MyVector(const char* str) : size(1), maxSize(1) {
    pdata = new char*[1];
    pdata[0] = new char[strlen(str) + 1];
    strcpy(pdata[0], str);
}

MyVector<char*>::MyVector(size_t initialSize) : size(0), maxSize(initialSize) {
    pdata = new char*[maxSize];
}

MyVector<char*>::MyVector(const MyVector& other) : size(other.size), maxSize(other.maxSize) {
    pdata = new char*[maxSize];
    for(size_t i = 0; i < size; ++i) {
        pdata[i] = new char[strlen(other.pdata[i]) + 1];
        strcpy(pdata[i], other.pdata[i]);
    }
}

MyVector<char*>::~MyVector() {
    for(size_t i = 0; i < size; ++i) {
        delete[] pdata[i];
    }
    delete[] pdata;
}

MyVector<char*>& MyVector<char*>::operator=(const MyVector& other) {
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

void MyVector<char*>::addElement(const char* element) {
    if(size >= maxSize) resize(maxSize * 2);
    pdata[size] = new char[strlen(element) + 1];
    strcpy(pdata[size], element);
    size++;
}

void MyVector<char*>::deleteElement(size_t index) {
    if(index >= size) return;

    delete[] pdata[index];

    for(size_t i = index; i < size - 1; ++i) {
        pdata[i] = pdata[i + 1];
    }

    size--;
    if(size < maxSize / 4 && maxSize > 1) resize(maxSize / 2);
}

int MyVector<char*>::find(const char* element) const {
    for(size_t i = 0; i < size; ++i) {
        if(strcmp(pdata[i], element) == 0) return i;
    }
    return -1;
}

char* MyVector<char*>::operator[](size_t index) {
    if(index >= size) throw std::out_of_range("Index out of range");
    return pdata[index];
}

const char* MyVector<char*>::operator[](size_t index) const {
    if(index >= size) throw std::out_of_range("Index out of range");
    return pdata[index];
}

void MyVector<char*>::sort() {
    std::sort(pdata, pdata + size, [](const char* a, const char* b) {
        return strcmp(a, b) < 0;
    });
}

size_t MyVector<char*>::getSize() const { return size; }

size_t MyVector<char*>::getMaxSize() const { return maxSize; }

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
