#include "Game.hpp"
#include <ctime>
#include <iostream>

Game::Game(void) :
	_gameOver(false) {
}

Game::Game(Game const &src) {
	if (this != &src)
		*this = src;
}

Game::~Game(void) {
}

Game		&Game::operator=(Game const &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}

void		Game::launch(void) {
	for (int i = 0; i < SIZE_BOARD; ++i) {
		for (int j = 0; j < SIZE_BOARD; ++j) {
			_board[i][j] = EMPTY;
		}
	}
}

void		Game::loop(void) {
	bool	turn(true);

	while (!_gameOver && 0) {
		if (turn) {
			waitP1();
		} else {
			waitP2();
		}
		display();
	}
}

void	Game::waitP1(void) {
	;
}

void	Game::waitP2(void) {
	;
}

void	Game::display(void) const {
	for (int i = 0; i < SIZE_BOARD; ++i) {
		for (int j = 0; j < SIZE_BOARD; ++j) {
			std::cout << _board[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}
