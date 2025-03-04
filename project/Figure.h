// Figure.h
#ifndef CHESSFIGURE_H
#define CHESSFIGURE_H

#include <iostream>

class Figure {
 private:
    char* name;
    char* color;
    char* position
 public:
    Figure(const char* name, const char* color, const char* position);
    ~Figure();

    char GetName() const;
    char GetColor() const;
    char GetPosition() const;

};

#endif  // FIGURE_H
