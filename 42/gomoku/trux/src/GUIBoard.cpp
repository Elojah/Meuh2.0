#include "GUIBoard.hpp"

GUIBoard::GUIBoard(void) {
}

GUIBoard::~GUIBoard(void)
{
	if (_window.isOpen())
		_window.close();
}

void	GUIBoard::init(int size)
{
	_size = size;
	(void)_size;
	_tBoard.loadFromFile("data/goban");
	if (!_window.isOpen())
		_window.create(sf::VideoMode(WIDTH, HEIGHT), "Gomoku");
	_window.clear(sf::Color(212, 177, 106));
	_window.setFramerateLimit(60);
	// sBoard.scale(_tBoard.getSize().x / WIDTH, _tBoard.getSize().y / HEIGHT);
	_sBoard.setTexture(_tBoard);
}

void	GUIBoard::render(void)
{
	_window.draw(_sBoard);
	_window.display();
}

int		GUIBoard::getEvent(void)
{
	while (_window.pollEvent(_event))
	{
		if (_event.type == sf::Event::Closed)
			return (EXIT);
	}
	return (E_EVENT);
}
