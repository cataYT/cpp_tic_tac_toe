#pragma once
#include "Player.h"
#include <vector>
#include <unordered_map>

class Game {
private:
	std::unordered_map<Player*, char> players;
	std::vector<char> pos = {
		' ', ' ', ' ',
		' ', ' ', ' ',
		' ', ' ', ' '
	};
	std::vector<std::vector<int>> win_positions = {
		{0, 1, 2}, {3, 4, 5}, {6, 7, 8},
		{0, 3, 6}, {1, 4, 7},{2, 5, 8},
		{0, 4, 8}, {2, 4, 6}
	};
public:
	void drawBoard();
	bool checkDraw();
	Player* checkWin();
	bool markBoard(int pos, char symbol);
public:
	Game(std::vector<Player*> _players);
	~Game();
};