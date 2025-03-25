#include "Figure.h"

#include <algorithm>
#include <cstring>
#include <fstream>
#include <string>

void Print(){
    std::cout << "+----+-----------------------------------" << std::endl;
    std::cout << "|    |    |    |    |    |    |    |    |" << std::endl;
    std::cout << "+----+-----------------------------------" << std::endl;
    std::cout << "|    |    |    |    |    |    |    |    |" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "|    |    |    |    |    |    |    |    |" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "|    |    |    |    |    |    |    |    |" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "|    |    |    |    |    |    |    |    |" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "|    |    |    |    |    |    |    |    |" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "7   |    |    |    |    |    |    |    |    |" << std::endl;
    std::cout << "   -----------------------------------------" << std::endl;
    std::cout << "8  |    |    |    |    |    |    |    |    |" << std::endl;
    std::cout << "   -----------------------------------------" << std::endl;

}

int main() {
    Figure figure("king", "white", "e1");
    std::cout << figure.GetName() << std::endl;
    Print();
    return 0;
}
