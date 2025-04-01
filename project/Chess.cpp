#include "Figure.h"

#include <algorithm>
#include <cstring>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

void Print(std::vector<std::vector<std::string>>& board) {
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

void Move(std::vector<std::vector<std::string>>& board, const std::string& move = ""){
    if (!move.empty() && move.size() == 5 && move[2] == '-') {
        std::string from = move.substr(0, 2);
        std::string to = move.substr(3, 2);

        int fromCol = std::tolower(from[0]) - 'a';
        int fromRow = 8 - (from[1] - '0');
        int toCol = std::tolower(to[0]) - 'a';
        int toRow = 8 - (to[1] - '0');

        if (fromRow >= 0 && fromRow < 8 && fromCol >= 0 && fromCol < 8 &&
            toRow >= 0 && toRow < 8 && toCol >= 0 && toCol < 8) {
            board[toRow][toCol] = board[fromRow][fromCol];
            board[fromRow][fromCol] = " ";
        }
    }
}

void FirstPlayerStep(){}

void SecondPlayerStep(){}

bool KingCheck(std::vector<std::vector<std::string>>& board){
    int countKing = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j<8; j++) {
            if (board[i][j] == " ♚ ") {
                countKing += 1;
            }
        }
    }
    return countKing != 2;
}

int GameEnding(std::vector<std::vector<std::string>>& board) {
    if (KingCheck(board)) {
        return 1;
    }
    return 0;
}

void StartApp(std::vector<std::vector<std::string>>& board) {
    bool GameContinues = true;
    while(GameContinues) {
        Print(board);

        std::string move;
        std::cin >> move;

        Move(board, move);

        if (GameEnding(board) == 1) {
            GameContinues = false;
        }
    }
    std::cout << "Игра конченая" << std::endl;
}

int main() {
    std::vector<std::vector<std::string>> board(8, std::vector<std::string>(8, " "));

    board[0] = {" ♜ ", " ♞ ", " ♝ ", " ♛ ", " ♚ ", " ♝ ", " ♞ ", " ♜ "};
    board[1] = {" ♟ ", " ♟ ", " ♟ ", " ♟ ", " ♟ ", " ♟ ", " ♟ ", " ♟ "};

    board[7] = {" ♜ ", " ♞ ", " ♝ ", " ♛ ", " ♚ ", " ♝ ", " ♞ ", " ♜ "};
    board[6] = {" ♟ ", " ♟ ", " ♟ ", " ♟ ", " ♟ ", " ♟ ", " ♟ ", " ♟ "};

    StartApp(board);

    return 0;
}
