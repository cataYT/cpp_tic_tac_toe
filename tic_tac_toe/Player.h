#pragma once

#include <string>

class Player {
public:
	std::string name;
	char symbol;
public:
	Player(std::string _name, char _symbol);
	~Player();
public:
	int validateMove(int player_input);
};