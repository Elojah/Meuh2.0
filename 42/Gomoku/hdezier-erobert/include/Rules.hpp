// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Rules.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/05/28 12:11:48 by hdezier           #+#    #+#             //
//   Updated: 2015/05/28 12:12:23 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef RULES_HPP
# define RULES_HPP

# include "Player.hpp"
# include "Cell.hpp"

class Board;

class Rules
{
public:

	/*DONT TOUCH ME*/
	enum eValidity
	{
		OK = 0,
		INVALID,
		WIN
	};

	static eValidity	makeMove(Board &b, Player::vec2 const &move,
								Cell::eValue player);
	static eValidity	simulateMove(Board &b, Player::vec2 const &move,
								Cell::eValue player);
private:
	Rules(void);
	~Rules(void);
	Rules(Rules const &src);
	Rules			&operator=(Rules const &rhs);

	static int			_nbCaptures[Cell::E_VALUE];
	static Player::vec2	_lastChance;

	static int			win(Cell &cell);
	static bool			insertDoubleFreethrees(Cell &cell);
	static bool			canCaptureFive(Cell const &cell, int dirWin);
	static eValidity	captureStone(Cell &cell, Cell::eValue player);
	static bool			canCaptureLast(Board const &b, Cell::eValue opponent);
};

#endif
