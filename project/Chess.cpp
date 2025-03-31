#include "Figure.h"

#include <algorithm>
#include <cstring>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

void Print(std::vector<std::string>& board, const std::string& move = "") {
    // Обработка хода, если он передан
    if (!move.empty() && move.size() == 5 && move[2] == '-') {
        std::string from = move.substr(0, 2);
        std::string to = move.substr(3, 2);

        // Преобразование координат (например, "e2" -> [6][4])
        int from_row = 8 - (from[1] - '0');
        int from_col = tolower(from[0]) - 'a';
        int to_row = 8 - (to[1] - '0');
        int to_col = tolower(to[0]) - 'a';

        // Проверка корректности координат
        if (from_row >= 0 && from_row < 8 && from_col >= 0 && from_col < 8 &&
            to_row >= 0 && to_row < 8 && to_col >= 0 && to_col < 8) {

            // Выполнение хода
            board[to_row][to_col] = board[from_row][from_col];
            board[from_row][from_col] = ' ';
        }
    }

    // Отображение доски
    std::cout << "   a   b   c   d   e   f   g   h\n";
    std::cout << " +---+---+---+---+---+---+---+---+\n";

    for (int i = 0; i < 8; ++i) {
        std::cout << 8 - i << "|";
        for (int j = 0; j < 8; ++j) {
            char piece = board[i][j];
            std::cout << " " << (piece == ' ' ? ' ' : piece) << " |";
        }
        std::cout << 8 - i << "\n +---+---+---+---+---+---+---+---+\n";
    }

    std::cout << "   a   b   c   d   e   f   g   h\n";
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
    std::vector<std::string> board = {
        "rnbqkbnr",
        "pppppppp",
        "        ",
        "        ",
        "        ",
        "        ",
        "PPPPPPPP",
        "RNBQKBNR"
    };
    Print(board);

    return 0;
}
