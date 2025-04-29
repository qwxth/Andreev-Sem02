// Figure.h
#ifndef FIGURE_H
#define FIGURE_H

#include <string>
#include <iostream>

class Figure {
 private:
    std::string name;
    std::string color;
    std::string position;
 public:
    Figure(const std::string name, const std::string color, const std::string position);
    ~Figure();

    std::string GetName() const;
    std::string GetColor() const;
    std::string GetPosition() const;

};

#endif  // FIGURE_H
