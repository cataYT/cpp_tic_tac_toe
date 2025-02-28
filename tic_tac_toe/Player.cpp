#include "Player.h"
#include <iostream>

Player::Player(std::string _name, char _symbol) {
	this->name = _name;
	this->symbol = _symbol;
}

int Player::validateMove(int player_input) {
	return player_input >= 0 and player_input <= 8;
}

Player::~Player() {
	this->name.clear();
	this->name.shrink_to_fit();
}