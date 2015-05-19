#include "Game.hpp"

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
	while (!_gameOver && 0) {
		;
	}
}
