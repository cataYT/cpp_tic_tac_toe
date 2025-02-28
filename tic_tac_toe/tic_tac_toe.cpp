#include <iostream>
#include "Game.h"

void input_plr(Player* player, Game* game) {
    while (true) {
        int turn;
        std::cout << player->name << "'s turn. Enter a number between 0 and 8: ";

        // Check if the input is an integer
        if (!(std::cin >> turn)) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            std::cout << "Invalid input. Please enter a number between 0 and 8." << std::endl;
            continue;
        }

        // Check if the input is within the valid range
        if (turn < 0 || turn > 8) {
            std::cout << "Invalid move. Enter a number between 0 and 8." << std::endl;
            continue;
        }

        if (player->validateMove(turn)) {
            if (game->markBoard(turn, player->symbol)) {
                game->drawBoard();
                return;
            }
            else {
                if (game->checkDraw()) {
                    std::cout << "This game has ended in a draw!" << std::endl;
                    break;
                }
                std::cout << "Position is already marked. Try again." << std::endl;
            }
        }
        else {
            std::cout << "Invalid move. Enter a number between 0 and 8." << std::endl;
        }
    }
}

int main() {
	Player* player1 = new Player("Player 1", 'X');
	Player* player2 = new Player("Player 2", 'O');
	while (player2->symbol == player1->symbol) {
		std::cout << "Players must have different symbols! Choose again." << std::endl;
		player2 = new Player("Player 2", 'O');
	}
	std::vector<Player*> players = { player1, player2 };
	Game* game = new Game(players);
	int turn = 0;
	while (true) {
		Player* current_player = players.at(turn);
		input_plr(current_player, game);
		Player* winner = game->checkWin();
		if (winner) {
			std::cout << winner->name << " has won the game!" << std::endl;
			break;
		}
		turn = 1 - turn;
	}
	delete player1;
	delete player2;
	delete game;
	return 0;
}