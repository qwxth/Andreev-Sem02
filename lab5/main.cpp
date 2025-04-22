#include <iostream>
#include "MyVector/MyVector.h"
#include "MySet/MySet.h"

int main() {
    MyVector<char*> elements("Hello!");
    elements.addElement("Привет!");
    elements.addElement("Привет!");
    elements.addElement("Привет!");
    elements.addElement("Привет!");
    elements.addElement("Привет!");
    std::cout << "Вектор elements: " << elements << std::endl;
    elements.addElement("Привет!");
    elements.addElement("Привет!");
    elements.addElement("Привет!");
    std::cout << "Вектор elements: " << elements << std::endl;
    MyVector<char*> elements1 = elements;
    std::cout << "Вектор elements1: " << elements1 << std::endl;
    for (int i = 0; i < MaxSize; i++)
        elements1.deleteElement(0);
    std::cout << "Вектор elements1: " << elements1 << std::endl;

    MySet set("Yes"), set1, set2;
    set.addElement("Привет!");
    set.addElement("No");
    char *str = "Hello!";
    set.addElement(str);
    std::cout << "Множество set: " << set << std::endl;
    set1.addElement("Cat");
    set1.addElement("No");
    set1.addElement("Привет!");
    set1.addElement("Привет!");
    set1.addElement("Привет!");
    set1.addElement("Привет!");
    set1.addElement("Привет!");
    set1.addElement("Привет!");
    std::cout << "Множество set1: " << set1 << std::endl;
    set2 = set1 - set;
    std::cout << "Множество set2=set1-set: " << set2 << std::endl;
    std::cout << "Множество set1: " << set1 << std::endl;
    std::cout << "Множество set: " << set << std::endl;
    set2 = set - set1;
    std::cout << "Множество set2=set-set1: " << set2 << std::endl;
    std::cout << "Множество set1: " << set1 << std::endl;
    std::cout << "Множество set: " << set << std::endl;
    set2 = set1 + set;
    std::cout << "Множество set2=set1+set: " << set2 << std::endl;
    std::cout << "Множество set1: " << set1 << std::endl;
    std::cout << "Множество set: " << set << std::endl;
    set2 = set1 * set;
    std::cout << "Множество set2=set1*set: " << set2 << std::endl;
    std::cout << "Множество set1: " << set1 << std::endl;
    std::cout << "Множество set: " << set << std::endl;
    MySet set3 = set2;
    std::cout << "Множество set3=set2: " << set3 << std::endl;
    if (set3 == set2)
        std::cout << "Множество set3=set2\n";
    else
        std::cout << "Множество set3!=set2\n";
    if (set3 == set1)
        std::cout << "Множество set3=set1\n";
    else
        std::cout << "Множество set3!=set1\n";
    if (set1 == set3)
        std::cout << "Множество set1=set3\n";
    else
        std::cout << "Множество set1!=set3\n";
    return 0;
}
