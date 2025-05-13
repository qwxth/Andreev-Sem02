// ChessBoard.h
#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <vector>
#include <memory>
#include "figure.h"

class ChessBoard {
private:
    std::vector<std::unique_ptr<Figure>> figures;
    Color currentTurn;

public:
    ChessBoard();

    void resetBoard();
    Figure* getFigureAt(const Position& pos) const;
    bool moveFigure(const Position& from, const Position& to);
    void displayBoard() const;
    Color getCurrentTurn() const;
    void switchTurn();
    bool isCheckmate() const;
    bool isCheck(Color color) const;

private:
    Position findKing(Color color) const;
};

#endif // CHESSBOARD_H
