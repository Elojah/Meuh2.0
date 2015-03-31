// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GUINCurses.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/31 14:35:05 by erobert           #+#    #+#             //
//   Updated: 2015/03/31 15:07:12 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GUI_NCURSES_HPP
# define GUI_NCURSES_HPP

# include "IGUINibbler.hpp"

class GUINCurses: public IGUINibbler
{
public:
	GUINCurses(void);
	~GUINCurses(void);

	virtual void			buildMap(std::vector<int> const &tMap);
	virtual void			updateDisplay(tNibbler const &tN, int apple);
	virtual Game::eInput	eventHandler(void);
private:
	std::vector<int>		_map;

	GUINCurses(GUINCurses const &gN);

	GUINCurses				&operator=(GUINCurses const &gN);
};

extern "C"
{
	GUINCurses				*createGUI(void);
	void					deleteGUI(GUINCurses *gN);
}

#endif
