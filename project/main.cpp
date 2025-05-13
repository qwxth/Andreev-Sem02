// main.cpp
#include <iostream>
#include <string>
#include "ChessBoard.h"

Position parsePosition(const std::string& input) {
    if (input.length() != 2) {
        return Position(-1, -1);
    }

    int x = input[0] - 'a';
    int y = 8 - (input[1] - '0');

    if (x < 0 || x >= 8 || y < 0 || y >= 8) {
        return Position(-1, -1);
    }

    return Position(x, y);
}

int main() {
    ChessBoard board;
    std::string input;

    std::cout << "Добро пожаловать в шахматы!" << std::endl;
    std::cout << "Для хода введите начальную и конечную позицию (например, e2e4)" << std::endl;
    std::cout << "Для выхода введите 'exit'" << std::endl;

    board.displayBoard();

    while (true) {
        std::cout << "Ход " << (board.getCurrentTurn() == Color::WHITE ? "белых" : "черных") << ": ";
        std::cin >> input;

        if (input == "exit") {
            break;
        }

        if (input.length() != 4) {
            std::cout << "Неправильный формат ввода. Пример: e2e4" << std::endl;
            continue;
        }

        Position from = parsePosition(input.substr(0, 2));
        Position to = parsePosition(input.substr(2, 2));

        if (!from.isValid() || !to.isValid()) {
            std::cout << "Неправильная позиция. Используйте a-h для столбцов и 1-8 для строк." << std::endl;
            continue;
        }

        if (board.moveFigure(from, to)) {
            board.displayBoard();

            if (board.isCheck(board.getCurrentTurn())) {
                std::cout << "Шах!" << std::endl;

                if (board.isCheckmate()) {
                    std::cout << "Мат! " << (board.getCurrentTurn() == Color::WHITE ? "Черные" : "Белые") << " победили!" << std::endl;
                    break;
                }
            }
        } else {
            std::cout << "Недопустимый ход. Попробуйте снова." << std::endl;
        }
    }

    std::cout << "Спасибо за игру!" << std::endl;
    return 0;
}
