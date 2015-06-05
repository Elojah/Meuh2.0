// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Rules.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/05/28 12:11:48 by hdezier           #+#    #+#             //
//   Updated: 2015/06/05 18:31:59 by erobert          ###   ########.fr       //
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
	enum eValidity
	{
		OK = 0,
		INVALID,
		WIN,
		LOOSE
	};

	static eValidity	makeMove(Board &b, Player &p1, Player &p2);
//	static eValidity	simulateMove(Board &b, Player::vec2 const &move,
//								Cell::eValue player);
private:
	static Cell const	*_winMove[Cell::E_VALUE];
	
	Rules(void);
	Rules(Rules const &src);
	~Rules(void);
	
	Rules			&operator=(Rules const &rhs);

	static int			win(Cell const &cell);
	static bool			insertDoubleFreethrees(Cell &cell);
	static bool			canCaptureFive(Cell const &cell, int dirWin);
	static eValidity	captureStone(Cell &cell, Player &player);
	static bool			canCaptureLast(Board const &b, Cell &cell,
									   Player &opponent);
};

#endif
