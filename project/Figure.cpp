#include "Figure.h"

#include <algorithm>
#include <cstring>
#include <fstream>
#include <string>

Figure::Figure(std::string n, std::string c, std::string p) {
    name = n;
    color = c;
    position = p;
}

Figure::~Figure() {
}

std::string Figure::GetName() const {
    return name;
}

std::string Figure::GetColor() const {
    return color;
}

std::string Figure::GetPosition() const {
    return position;
}
