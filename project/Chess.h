#ifndef CHESS_H
#define CHESS_H

#include <vector>
#include <string>

void Print(std::vector<std::vector<std::string>>& board);
void Move(std::vector<std::vector<std::string>>& board);

void FirstPlayerStep();
void SecondPlayerStep();

int GameEnding(std::vector<std::vector<std::string>>& board);

void Game(std::vector<std::vector<std::string>>& board);

int StartApp();

#endif // CHESS_H
