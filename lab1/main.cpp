#include <iostream>
#include "mymath/mymath.h"
#include "myproduct/myproduct.h"


int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Я умею суммировать! Зацени 10 + 32 = ";
    std::cout << mymath::sum(10, 32) << std::endl;
    std::cout << "Я умею умножать! Зацени 10 * 32 = ";
    std::cout << myproduct::product(10, 32) << std::endl;

    return 0;
}
