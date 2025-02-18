#include <iostream>

#include "directory/mymath.h"
#include "directory/myproduct.h"



int main() {
    std::cout << "я умею суммировать! зацени 10 + 32 = ";
    std::cout << mymath::sum(10, 32) << std::endl;

    std::cout << "я умею умножать! зацени 10 * 32 = ";
    std::cout << myproduct::product(10, 32) << std::endl;

    return 0;
}
