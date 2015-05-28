#include "UserInterface.hpp"

UserInterface::UserInterface(void)
{
	float	scale[0];

	_tBoard.loadFromFile("data/goban");
	if (!_window.isOpen())
		_window.create(sf::VideoMode(WIDTH, HEIGHT), "Gomoku");
	_window.clear(sf::Color(212, 177, 106));
	_window.setFramerateLimit(60);
	scale[0] = WIDTH;
	scale[0] /= _tBoard.getSize().x;
	scale[1] = HEIGHT;
	scale[1] /= _tBoard.getSize().y;
	_sBoard.scale(scale[0], scale[1]);
	_sBoard.setTexture(_tBoard);
}

UserInterface::~UserInterface(void)
{
	if (_window.isOpen())
		_window.close();
}

void	UserInterface::init(int size)
{
	/*Nothing to do here except if size change*/
}

void	UserInterface::render(Board const &b
	, Player const &p1, Player const &p2)
{
	_window.draw(_sBoard);
	_window.display();
}

const UserInterface::sEvent	&UserInterface::getEvent(void)
{
	static sEvent		event;

	event.e = E_EVENT;
	_window.waitEvent(_event);
	if (_event.type == sf::Event::Closed || _event.key.code == 'q')
		event.e = EXIT;
	return (event);
}
