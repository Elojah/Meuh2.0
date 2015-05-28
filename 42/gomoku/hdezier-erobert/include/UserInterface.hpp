// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   UserInterface.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/05/28 12:07:12 by erobert           #+#    #+#             //
//   Updated: 2015/05/28 13:04:17 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef USER_INTERFACE_HPP
# define USER_INTERFACE_HPP

# define HEIGHT 1000
# define WIDTH 1000

# include "SFML/Graphics.hpp"

class Board;
class Player;

class UserInterface
{
public:
	enum eEvent
	{
		EXIT = 0,
		MOUSE,
		KEY,
		E_EVENT
	};

	struct sEvent
	{
		eEvent			e;
		int				x;
		int				y;
	};

	UserInterface(void);
	~UserInterface(void);

	void				init(int size);
	void				render(Board const &b, Player const &p1,
							   Player const &p2);
	sEvent const		&getEvent(void);
private:
	enum eStone
	{
		BLACK = 0,
		WHITE,
		HELP,
		E_STONE
	};

	size_t				_size;
	sf::RenderWindow	_window;
	sf::Event			_event;
	sf::Texture			_tBoard;
	sf::Sprite			_sBoard;
	sf::CircleShape     _stone[E_STONE];
	sf::Color			_black;

	UserInterface(UserInterface const &src);

	UserInterface		&operator=(UserInterface const &rhs);

	void				drawStone(int x, int y, eStone stone);
};

#endif
