// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GUIBoard.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/05/25 17:46:56 by erobert           #+#    #+#             //
//   Updated: 2015/05/25 18:00:01 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef G_U_I_BOARD_H
# define G_U_I_BOARD_H

# include "SFML/Graphics.hpp"

# define HEIGHT 1024
# define WIDTH 1024

class GUIBoard
{
public:
	enum eEvent
	{
		EXIT,
		MOUSE,
		KEY,
		E_EVENT
	};

	struct sEvent
	{
		eEvent			key;
		char			c;
		int				x;
		int				y;
	};

	GUIBoard(void);
	~GUIBoard(void);

	void				init(int size);
	void				render(int *board);
	int					getEvent(void);
private:
	size_t				_size;
	sf::RenderWindow	_window;
	sf::Event			_event;
	sf::Texture			_tBoard;
	sf::Sprite			_sBoard;

	GUIBoard(GUIBoard const &rhs);

	GUIBoard			&operator=(GUIBoard const &rhs);
};

#endif
