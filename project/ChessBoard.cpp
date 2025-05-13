// ChessBoard.cpp
#include "ChessBoard.h"
#include <iostream>
#include <algorithm>

ChessBoard::ChessBoard() : currentTurn(Color::WHITE) {
    resetBoard();
}

void ChessBoard::resetBoard() {
    figures.clear();

    // Добавляем пешки
    for (int i = 0; i < 8; ++i) {
        figures.push_back(std::make_unique<Pawn>(Color::WHITE, Position(i, 6)));
        figures.push_back(std::make_unique<Pawn>(Color::BLACK, Position(i, 1)));
    }

    // Добавляем ладьи
    figures.push_back(std::make_unique<Rook>(Color::WHITE, Position(0, 7)));
    figures.push_back(std::make_unique<Rook>(Color::WHITE, Position(7, 7)));
    figures.push_back(std::make_unique<Rook>(Color::BLACK, Position(0, 0)));
    figures.push_back(std::make_unique<Rook>(Color::BLACK, Position(7, 0)));

    // Добавляем коней
    figures.push_back(std::make_unique<Knight>(Color::WHITE, Position(1, 7)));
    figures.push_back(std::make_unique<Knight>(Color::WHITE, Position(6, 7)));
    figures.push_back(std::make_unique<Knight>(Color::BLACK, Position(1, 0)));
    figures.push_back(std::make_unique<Knight>(Color::BLACK, Position(6, 0)));

    // Добавляем слонов
    figures.push_back(std::make_unique<Bishop>(Color::WHITE, Position(2, 7)));
    figures.push_back(std::make_unique<Bishop>(Color::WHITE, Position(5, 7)));
    figures.push_back(std::make_unique<Bishop>(Color::BLACK, Position(2, 0)));
    figures.push_back(std::make_unique<Bishop>(Color::BLACK, Position(5, 0)));

    // Добавляем ферзей
    figures.push_back(std::make_unique<Queen>(Color::WHITE, Position(3, 7)));
    figures.push_back(std::make_unique<Queen>(Color::BLACK, Position(3, 0)));

    // Добавляем королей
    figures.push_back(std::make_unique<King>(Color::WHITE, Position(4, 7)));
    figures.push_back(std::make_unique<King>(Color::BLACK, Position(4, 0)));

    currentTurn = Color::WHITE;
}

Figure* ChessBoard::getFigureAt(const Position& pos) const {
    for (const auto& figure : figures) {
        if (figure->getPosition() == pos) {
            return figure.get();
        }
    }
    return nullptr;
}

bool ChessBoard::moveFigure(const Position& from, const Position& to) {
    Figure* figure = getFigureAt(from);

    if (!figure) {
        return false;
    }

    if (figure->getColor() != currentTurn) {
        return false;
    }

    if (!figure->canMoveTo(to, *this)) {
        return false;
    }

    // Проверяем, есть ли фигура в месте назначения
    Figure* capturedFigure = getFigureAt(to);
    if (capturedFigure) {
        // Удаляем взятую фигуру
        auto it = std::remove_if(figures.begin(), figures.end(),
            [to](const std::unique_ptr<Figure>& f) {
                return f->getPosition() == to;
            });
        figures.erase(it, figures.end());
    }

    // Перемещаем фигуру
    figure->setPosition(to);

    // Проверяем, не ставит ли ход короля под шах
    if (isCheck(currentTurn)) {
        // Отменяем ход
        figure->setPosition(from);
        if (capturedFigure) {
            // Для полной реализации нужен механизм истории ходов
            // Для простоты не реализуем полностью
            return false;
        }
        return false;
    }

    switchTurn();
    return true;
}

void ChessBoard::displayBoard() const {
    std::cout << "  a b c d e f g h" << std::endl;
    for (int y = 0; y < 8; ++y) {
        std::cout << 8 - y << " ";
        for (int x = 0; x < 8; ++x) {
            Figure* figure = getFigureAt(Position(x, y));
            if (figure) {
                std::cout << figure->getSymbol() << " ";
            } else {
                // Разные символы для белых и черных клеток
                char squareChar = ((x + y) % 2 == 0) ? '.' : ' ';
                std::cout << squareChar << " ";
            }
        }
        std::cout << 8 - y << std::endl;
    }
    std::cout << "  a b c d e f g h" << std::endl;

    std::cout << "Текущий ход: " << (currentTurn == Color::WHITE ? "Белые" : "Черные") << std::endl;
}

Color ChessBoard::getCurrentTurn() const {
    return currentTurn;
}

void ChessBoard::switchTurn() {
    currentTurn = (currentTurn == Color::WHITE) ? Color::BLACK : Color::WHITE;
}

Position ChessBoard::findKing(Color color) const {
    for (const auto& figure : figures) {
        if (figure->getColor() == color && dynamic_cast<King*>(figure.get())) {
            return figure->getPosition();
        }
    }
    return Position(-1, -1);
}

bool ChessBoard::isCheck(Color color) const {
    Position kingPos = findKing(color);
    Color opponentColor = (color == Color::WHITE) ? Color::BLACK : Color::WHITE;

    for (const auto& figure : figures) {
        if (figure->getColor() == opponentColor) {
            auto possibleMoves = figure->getPossibleMoves(*this);
            if (std::find(possibleMoves.begin(), possibleMoves.end(), kingPos) != possibleMoves.end()) {
                return true;
            }
        }
    }

    return false;
}

bool ChessBoard::isCheckmate() const {
    // Сначала проверяем, находится ли текущий игрок под шахом
    if (!isCheck(currentTurn)) {
        return false;
    }

    // Затем проверяем, может ли какой-либо ход вывести игрока из шаха
    for (const auto& figure : figures) {
        if (figure->getColor() == currentTurn) {
            Position originalPos = figure->getPosition();
            auto possibleMoves = figure->getPossibleMoves(*this);

            for (const auto& move : possibleMoves) {
                // Проверяем, выводит ли этот ход из шаха
                // Мы делаем временное перемещение фигуры и проверяем состояние шаха
                Figure* capturedFigure = getFigureAt(move);
                Figure* movingFigure = figure.get();

                // Временно удаляем потенциально съеденную фигуру
                std::unique_ptr<Figure> capturedCopy;
                if (capturedFigure && capturedFigure->getColor() != currentTurn) {
                    auto it = std::find_if(figures.begin(), figures.end(),
                        [capturedFigure](const std::unique_ptr<Figure>& f) {
                            return f.get() == capturedFigure;
                        });

                    if (it != figures.end()) {
                        // Временно сохраняем указатель на съеденную фигуру
                        capturedCopy = std::move(*it);
                        it->reset();
                    }
                }

                // Временно перемещаем фигуру
                const_cast<Figure*>(movingFigure)->setPosition(move);

                // Проверяем, под шахом ли король
                bool stillInCheck = isCheck(currentTurn);

                // Возвращаем фигуру на исходную позицию
                const_cast<Figure*>(movingFigure)->setPosition(originalPos);

                // Восстанавливаем съеденную фигуру, если была
                if (capturedCopy) {
                    auto it = std::find_if(figures.begin(), figures.end(),
                        [](const std::unique_ptr<Figure>& f) {
                            return f.get() == nullptr;
                        });

                    if (it != figures.end()) {
                        *it = std::move(capturedCopy);
                    }
                }

                // Если нашли ход, выводящий из шаха
                if (!stillInCheck) {
                    return false;
                }
            }
        }
    }

    // Нет допустимых ходов, чтобы выйти из шаха
    return true;
}
