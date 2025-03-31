#include "Figure.h"

#include <algorithm>
#include <cstring>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

void Print(){
    std::cout << "   -----------------------------------------" << std::endl;
    for (int i = 0; i < 8; ++i) {
        std::cout << 8 - i << "  |";
        for (int j = 0; j < 8; ++j) {
            std::cout << std::setw(5) << "|";
        }
        std::cout << std::endl;
        std::cout << "   -----------------------------------------" << std::endl;
    }
    std::cout << "      a    b    c    d    e    f    g    h  " << std::endl;
}

int main() {
    Figure figure1("king", "white", "e2");
    Figure figure2("elefant", "white", "e1");
    Figure figure3("pown", "white", "e3");

    Figure figure4("rook", "white", "e4");
    Figure figure5("quin", "white", "e5");


    std::vector<Figure> figures = {figure1, figure2, figure3, figure4, figure5};

    std::cout << figures[0].GetName() << std::endl;
    std::cout << figures[0].GetPosition() << std::endl;

    std::cout << figures[1].GetName() << std::endl;
    std::cout << figures[2].GetName() << std::endl;


    Print();

    return 0;
}
