// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GUINCurses.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/31 14:35:05 by erobert           #+#    #+#             //
//   Updated: 2015/04/07 19:08:43 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GUI_NCURSES_HPP
# define GUI_NCURSES_HPP

# include <ncurses.h>
# include "SFML/Graphics.hpp"
# include "IGUINibbler.hpp"

class GUINCurses: public IGUINibbler
{
public:
	GUINCurses(void);
	~GUINCurses(void);

	virtual void			buildMap(std::vector<int> const &tMap,
									 int height, int width);
	virtual void			updateDisplay(tNibbler const &tN, int apple);
	virtual Game::eInput	eventHandler(void);
private:
	int						_cellSize;
	std::vector<int>		_map;
	int						_height;
	int						_width;
	int						_input[Game::E_INPUT];
	sf::RenderWindow		_window;
	sf::Event				_event;
	sf::Texture				_tGrass;
	sf::Sprite				_sGrass;
	sf::Vector2f			_v;
	sf::RectangleShape		_w;
	sf::CircleShape			_a;
	sf::CircleShape			_h;
	sf::RectangleShape		_b;

	GUINCurses(GUINCurses const &gN);

	GUINCurses				&operator=(GUINCurses const &gN);
};

extern "C"
{
	GUINCurses				*createGUI(void);
	void					deleteGUI(GUINCurses *gN);
}

#endif
