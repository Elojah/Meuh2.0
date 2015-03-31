// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GUINCurses.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/31 14:44:53 by erobert           #+#    #+#             //
//   Updated: 2015/03/31 15:07:22 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "GUINCurses.hpp"

GUINCurses::GUINCurses(void) {}
GUINCurses::~GUINCurses(void) {}

void				GUINCurses::buildMap(std::vector<int> const &map)
{
	_map = map;
	std::cout << "Map buid." << std::endl;
}
void				GUINCurses::updateDisplay(tNibbler const &tN, int apple)
{
	(void)tN; (void)apple;
	std::cout << "YESSS" << std::endl;
}
Game::eInput		GUINCurses::eventHandler(void)
{
	std::cout << "eventHandler" << std::endl;
	return (Game::UP);
}

GUINCurses			*createGUI(void)
{
	return (new GUINCurses);
}
void				deleteGUI(GUINCurses *gN)
{
	delete gN;
}
