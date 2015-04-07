// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 12:33:32 by erobert           #+#    #+#             //
/*   Updated: 2015/01/12 08:30:45 by rbobillo         ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#include "Game.hpp"

Game::Game(void):
	_pAmount(1)
{
//	std::cout << "Start game" << std::endl;
}
Game::Game(int const pAmount):
	_pAmount(pAmount)
{
//	std::cout << "Start game" << std::endl;
}
Game::Game(Game const &g)
{
	*this = g;
//	std::cout << "Start game" << std::endl;
}
Game::~Game(void)
{
//	std::cout << "Leave game" << std::endl;
}

Game		&Game::operator=(Game const &g)
{
	if (this != &g)
	{
		_pAmount = g.getPAmount();
		_level = g.getLevel();
		_difficulty = g.getDifficulty();
	}
	return (*this);
}

int			Game::getPAmount(void) const
{
	return (_pAmount);
}
void		Game::setLevel(int const level)
{
	if (level > 0)
		_level = level;
}
int			Game::getLevel(void) const
{
	return (_level);
}
void		Game::setDifficulty(int const difficulty)
{
	if (difficulty > -1)
		_difficulty = difficulty;
}
int			Game::getDifficulty(void) const
{
	return (_difficulty);
}
