#include <vector>
#include <iostream>

enum class PieceType { None, Pawn, Rook, Knight, Bishop, Queen, King };
enum class Color { None, White, Black };

struct ChessPiece {
    PieceType type;
    Color color;

    ChessPiece(PieceType t = PieceType::None, Color c = Color::None)
        : type(t), color(c) {}
};

int main() {
    std::vector<std::vector<ChessPiece>> board(8, std::vector<ChessPiece>(8));

    // Белые фигуры
    board[7][0] = ChessPiece(PieceType::Rook, Color::White);    // a1
    board[7][1] = ChessPiece(PieceType::Knight, Color::White);  // b1
    board[7][2] = ChessPiece(PieceType::Bishop, Color::White);  // c1
    board[7][3] = ChessPiece(PieceType::Queen, Color::White);   // d1
    board[7][4] = ChessPiece(PieceType::King, Color::White);    // e1
    board[7][5] = ChessPiece(PieceType::Bishop, Color::White);  // f1
    board[7][6] = ChessPiece(PieceType::Knight, Color::White);  // g1
    board[7][7] = ChessPiece(PieceType::Rook, Color::White);    // h1

    // Белые пешки
    for(int col = 0; col < 8; ++col) {
        board[6][col] = ChessPiece(PieceType::Pawn, Color::White);
    }

    // Черные фигуры
    board[0][0] = ChessPiece(PieceType::Rook, Color::Black);    // a8
    board[0][1] = ChessPiece(PieceType::Knight, Color::Black);  // b8
    board[0][2] = ChessPiece(PieceType::Bishop, Color::Black);  // c8
    board[0][3] = ChessPiece(PieceType::Queen, Color::Black);   // d8
    board[0][4] = ChessPiece(PieceType::King, Color::Black);    // e8
    board[0][5] = ChessPiece(PieceType::Bishop, Color::Black);  // f8
    board[0][6] = ChessPiece(PieceType::Knight, Color::Black);  // g8
    board[0][7] = ChessPiece(PieceType::Rook, Color::Black);    // h8

    // Черные пешки
    for(int col = 0; col < 8; ++col) {
        board[1][col] = ChessPiece(PieceType::Pawn, Color::Black);
    }



    return 0;
}
