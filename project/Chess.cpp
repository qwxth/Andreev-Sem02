#include "Figure.h"

#include <algorithm>
#include <cstring>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

void Print(std::vector<std::vector<std::string>>& board, const std::string& move = "") {
    // Обработка хода
    if (!move.empty() && move.size() == 5 && move[2] == '-') {
        std::string from = move.substr(0, 2);
        std::string to = move.substr(3, 2);

        // Конвертация координат
        int from_col = std::tolower(from[0]) - 'a';
        int from_row = 8 - (from[1] - '0');
        int to_col = std::tolower(to[0]) - 'a';
        int to_row = 8 - (to[1] - '0');

        // Проверка границ и выполнение хода
        if (from_row >= 0 && from_row < 8 && from_col >= 0 && from_col < 8 &&
            to_row >= 0 && to_row < 8 && to_col >= 0 && to_col < 8) {
            board[to_row][to_col] = board[from_row][from_col];
            board[from_row][from_col] = " ";
        }
    }

    // Отображение доски
    std::cout << "    a    b    c    d    e    f    g    h\n";
    std::cout << "  +----+----+----+----+----+----+----+----+\n";

    for (int i = 0; i < 8; ++i) {
        std::cout << 8 - i << " |";
        for (int j = 0; j < 8; ++j) {
            std::cout << std::setw(3) << board[i][j] << " |";
        }
        std::cout << " " << 8 - i << "\n  +----+----+----+----+----+----+----+----+\n";
    }

    std::cout << "    a    b    c    d    e    f    g    h\n";
}

void FirstPlayerStep(){}

void SecondPlayerStep(){}

void StartApp(bool gameGoing) {
    while (gameGoing == true) {
        FirstPlayerStep();
        SecondPlayerStep();

    }
}

int main() {
    std::vector<std::vector<std::string>> board(8, std::vector<std::string>(8, " "));

    // Белые фигуры
    board[0] = {" ♜ ", " ♞ ", " ♝ ", " ♛ ", " ♚ ", " ♝ ", " ♞ ", " ♜ "};
    board[1] = {" ♟ ", " ♟ ", " ♟ ", " ♟ ", " ♟ ", " ♟ ", " ♟ ", " ♟ "};

    // Черные фигуры
    board[7] = {" ♜ ", " ♞ ", " ♝ ", " ♛ ", " ♚ ", " ♝ ", " ♞ ", " ♜ "};
    board[6] = {" ♟ ", " ♟ ", " ♟ ", " ♟ ", " ♟ ", " ♟ ", " ♟ ", " ♟ "};

    Print(board);
    while(true) {
        std::string move;
        std::cin >> move;

        Print(board, move);
    }
    return 0;
}
