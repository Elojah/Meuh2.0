// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GUIBoard.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/05/25 17:46:56 by erobert           #+#    #+#             //
//   Updated: 2015/05/26 15:48:44 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GUI_BOARD_HPP
# define GUI_BOARD_HPP

# include "SFML/Graphics.hpp"

# define HEIGHT 1024
# define WIDTH 1024

class GUIBoard
{
public:
	enum eCell
	{
		EMPTY,
		BLACK,
		WHITE
	};
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
		int				x;
		int				y;
	};

	GUIBoard(void);
	~GUIBoard(void);

	void				init(int size);
	void				render(eCell const **board);
	sEvent				getEvent(void);
private:
	size_t				_size;
	sf::RenderWindow	_window;
	sf::Event			_event;
	sf::Texture			_tBoard;
	sf::Sprite			_sBoard;
	sf::CircleShape		_stone;

	GUIBoard(GUIBoard const &rhs);

	GUIBoard			&operator=(GUIBoard const &rhs);
};

#endif
