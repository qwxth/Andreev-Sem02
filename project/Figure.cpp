#include "Figure.h"

#include <algorithm>
#include <cstring>
#include <fstream>

Figure::Figure(char* name, char* color, char* position) {
    name = h;
    color = m;
    position = s;
}

Figure::~Figure() {
    delete[] name;
    delete[] color;
    delete[] position;
    name = nullptr;
    color = nullptr;
    position = nullptr;
}

char Figure::GetName() const {
    return name;
}

char Figure::GetColor() const {
    return color;
}

char Figure::GetPosition() const {
    return position;
}

int main() {
    Figure figure(king, white, e1);

    std::cout << figure.GetName << std::endl;
    return 0;
}
