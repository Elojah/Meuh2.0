#ifndef USER_INTERFACE_H
# define USER_INTERFACE_H

# define HEIGHT 1024
# define WIDTH 1024

# include "SFML/Graphics.hpp"

class Board;
class Player;

class UserInterface
{
public:
	UserInterface(void);
	~UserInterface(void);

	enum eEvent
	{
		EXIT,
		MOUSE,
		KEY,
		E_EVENT
	};

	struct sEvent
	{
		eEvent			e;
		char			c;
		int				x;
		int				y;
	};

	void			init(int size);
	void			render(Board const &b, Player const &p1, Player const &p2);
	const sEvent	&getEvent(void);

protected:
private:
	UserInterface(UserInterface const &src);
	UserInterface&	operator=(UserInterface const &rhs);

	sf::RenderWindow	_window;
	sf::Event			_event;
	sf::Texture			_tBoard;
	sf::Sprite			_sBoard;
	unsigned int		_size;
};

#endif
