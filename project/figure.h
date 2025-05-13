// figure.h
#ifndef FIGURE_H
#define FIGURE_H

#include <vector>
#include <string>

enum class Color { WHITE, BLACK };

struct Position {
    int x; // Колонка (0-7, представляет A-H)
    int y; // Строка (0-7, представляет 1-8)

    Position(int x = 0, int y = 0) : x(x), y(y) {}

    bool isValid() const {
        return x >= 0 && x < 8 && y >= 0 && y < 8;
    }

    bool operator==(const Position& other) const {
        return x == other.x && y == other.y;
    }
};

class Figure {
protected:
    Color color;
    Position pos;
    std::string symbol;

public:
    Figure(Color c, Position p, std::string s);
    virtual ~Figure() = default;

    Color getColor() const;
    Position getPosition() const;
    void setPosition(Position p);
    std::string getSymbol() const;

    virtual std::vector<Position> getPossibleMoves(const class ChessBoard& board) const = 0;
    virtual bool canMoveTo(const Position& newPos, const ChessBoard& board) const;
};

class Pawn : public Figure {
public:
    Pawn(Color c, Position p);
    std::vector<Position> getPossibleMoves(const ChessBoard& board) const override;
};

class Rook : public Figure {
public:
    Rook(Color c, Position p);
    std::vector<Position> getPossibleMoves(const ChessBoard& board) const override;
};

class Knight : public Figure {
public:
    Knight(Color c, Position p);
    std::vector<Position> getPossibleMoves(const ChessBoard& board) const override;
};

class Bishop : public Figure {
public:
    Bishop(Color c, Position p);
    std::vector<Position> getPossibleMoves(const ChessBoard& board) const override;
};

class Queen : public Figure {
public:
    Queen(Color c, Position p);
    std::vector<Position> getPossibleMoves(const ChessBoard& board) const override;
};

class King : public Figure {
public:
    King(Color c, Position p);
    std::vector<Position> getPossibleMoves(const ChessBoard& board) const override;
};

#endif // FIGURE_H
