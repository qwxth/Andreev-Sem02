// figure.cpp
#include "figure.h"
#include "ChessBoard.h"
#include <algorithm>

Figure::Figure(Color c, Position p, std::string s) : color(c), pos(p), symbol(s) {}

Color Figure::getColor() const {
    return color;
}

Position Figure::getPosition() const {
    return pos;
}

void Figure::setPosition(Position p) {
    pos = p;
}

std::string Figure::getSymbol() const {
    return symbol;
}

bool Figure::canMoveTo(const Position& newPos, const ChessBoard& board) const {
    if (!newPos.isValid()) {
        return false;
    }

    auto possibleMoves = getPossibleMoves(board);
    return std::find(possibleMoves.begin(), possibleMoves.end(), newPos) != possibleMoves.end();
}

// Реализация пешки
Pawn::Pawn(Color c, Position p) : Figure(c, p, c == Color::WHITE ? "♙" : "♟") {}

std::vector<Position> Pawn::getPossibleMoves(const ChessBoard& board) const {
    std::vector<Position> moves;
    int direction = (color == Color::WHITE) ? -1 : 1;
    Position forward(pos.x, pos.y + direction);

    // Ход вперед на одну клетку
    if (forward.isValid() && !board.getFigureAt(forward)) {
        moves.push_back(forward);

        // Первый ход может быть на две клетки
        if ((color == Color::WHITE && pos.y == 6) || (color == Color::BLACK && pos.y == 1)) {
            Position twoForward(pos.x, pos.y + 2 * direction);
            if (twoForward.isValid() && !board.getFigureAt(twoForward)) {
                moves.push_back(twoForward);
            }
        }
    }

    // Взятие по диагонали
    Position captureLeft(pos.x - 1, pos.y + direction);
    Position captureRight(pos.x + 1, pos.y + direction);

    if (captureLeft.isValid()) {
        Figure* figureAtLeft = board.getFigureAt(captureLeft);
        if (figureAtLeft && figureAtLeft->getColor() != color) {
            moves.push_back(captureLeft);
        }
    }

    if (captureRight.isValid()) {
        Figure* figureAtRight = board.getFigureAt(captureRight);
        if (figureAtRight && figureAtRight->getColor() != color) {
            moves.push_back(captureRight);
        }
    }

    return moves;
}

// Реализация ладьи
Rook::Rook(Color c, Position p) : Figure(c, p, c == Color::WHITE ? "♖" : "♜") {}

std::vector<Position> Rook::getPossibleMoves(const ChessBoard& board) const {
    std::vector<Position> moves;

    // Направления: вверх, вправо, вниз, влево
    const int dx[] = {0, 1, 0, -1};
    const int dy[] = {-1, 0, 1, 0};

    for (int i = 0; i < 4; ++i) {
        for (int step = 1; step < 8; ++step) {
            Position newPos(pos.x + dx[i] * step, pos.y + dy[i] * step);
            if (!newPos.isValid()) {
                break;
            }

            Figure* figureAtPos = board.getFigureAt(newPos);
            if (!figureAtPos) {
                moves.push_back(newPos);
            } else {
                if (figureAtPos->getColor() != color) {
                    moves.push_back(newPos);
                }
                break;
            }
        }
    }

    return moves;
}

// Реализация коня
Knight::Knight(Color c, Position p) : Figure(c, p, c == Color::WHITE ? "♘" : "♞") {}

std::vector<Position> Knight::getPossibleMoves(const ChessBoard& board) const {
    std::vector<Position> moves;

    // Ходы коня буквой "Г"
    const int knightMoves[8][2] = {
        {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
        {1, -2}, {1, 2}, {2, -1}, {2, 1}
    };

    for (auto move : knightMoves) {
        Position newPos(pos.x + move[0], pos.y + move[1]);
        if (newPos.isValid()) {
            Figure* figureAtPos = board.getFigureAt(newPos);
            if (!figureAtPos || figureAtPos->getColor() != color) {
                moves.push_back(newPos);
            }
        }
    }

    return moves;
}

// Реализация слона
Bishop::Bishop(Color c, Position p) : Figure(c, p, c == Color::WHITE ? "♗" : "♝") {}

std::vector<Position> Bishop::getPossibleMoves(const ChessBoard& board) const {
    std::vector<Position> moves;

    // Диагональные направления
    const int dx[] = {-1, 1, 1, -1};
    const int dy[] = {-1, -1, 1, 1};

    for (int i = 0; i < 4; ++i) {
        for (int step = 1; step < 8; ++step) {
            Position newPos(pos.x + dx[i] * step, pos.y + dy[i] * step);
            if (!newPos.isValid()) {
                break;
            }

            Figure* figureAtPos = board.getFigureAt(newPos);
            if (!figureAtPos) {
                moves.push_back(newPos);
            } else {
                if (figureAtPos->getColor() != color) {
                    moves.push_back(newPos);
                }
                break;
            }
        }
    }

    return moves;
}

// Реализация ферзя
Queen::Queen(Color c, Position p) : Figure(c, p, c == Color::WHITE ? "♕" : "♛") {}

std::vector<Position> Queen::getPossibleMoves(const ChessBoard& board) const {
    std::vector<Position> moves;

    // Ферзь ходит как ладья и слон вместе взятые
    const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    const int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

    for (int i = 0; i < 8; ++i) {
        for (int step = 1; step < 8; ++step) {
            Position newPos(pos.x + dx[i] * step, pos.y + dy[i] * step);
            if (!newPos.isValid()) {
                break;
            }

            Figure* figureAtPos = board.getFigureAt(newPos);
            if (!figureAtPos) {
                moves.push_back(newPos);
            } else {
                if (figureAtPos->getColor() != color) {
                    moves.push_back(newPos);
                }
                break;
            }
        }
    }

    return moves;
}

// Реализация короля
King::King(Color c, Position p) : Figure(c, p, c == Color::WHITE ? "♔" : "♚") {}

std::vector<Position> King::getPossibleMoves(const ChessBoard& board) const {
    std::vector<Position> moves;

    // Король ходит на одну клетку в любом направлении
    const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    const int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

    for (int i = 0; i < 8; ++i) {
        Position newPos(pos.x + dx[i], pos.y + dy[i]);
        if (newPos.isValid()) {
            Figure* figureAtPos = board.getFigureAt(newPos);
            if (!figureAtPos || figureAtPos->getColor() != color) {
                moves.push_back(newPos);
            }
        }
    }

    return moves;
}
