#include "Game.h"
#include <iostream>
#include <algorithm>

Game::Game(std::vector<Player*> _player) {
	if (_player.size() == 2) {
		this->players[_player.at(0)] = 'X';
		this->players[_player.at(1)] = 'O';
	}
}

void Game::drawBoard() {
	std::cout << "\033[4m" << this->pos[0] << '|' << this->pos[1] << '|' << this->pos[2] << '\n';
	std::cout << this->pos[3] << '|' << this->pos[4] << '|' << this->pos[5] << "\033[0m" << '\n';
	std::cout << this->pos[6] << '|' << this->pos[7] << '|' << this->pos[8] << '\n';
}

bool Game::checkDraw() {
	bool allFilled = std::all_of(this->pos.begin(), this->pos.end(), [&](char pos) { return pos != ' '; });
	bool noWinner = this->checkWin() == nullptr;
	return allFilled && noWinner;
}

Player* Game::checkWin() {
	for (auto& player : this->players) {
		for (auto& win_pos : this->win_positions) {
			if (std::all_of(win_pos.begin(), win_pos.end(), [&](int pos) { return this->pos[pos] == player.second; })) {
				return player.first;
			}
		}
	}
	return nullptr;
}

bool Game::markBoard(int pos, char symbol) {
	if (this->pos[pos] == ' ') {
		this->pos[pos] = symbol;
		return true;
	}
	return false;
}

Game::~Game() {
	this->players.clear();
	std::unordered_map<Player*, char>().swap(this->players);

	this->pos.clear();
	this->pos.shrink_to_fit();

	this->win_positions.clear();
	this->win_positions.shrink_to_fit();
}