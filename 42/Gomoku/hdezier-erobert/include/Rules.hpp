// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Rules.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/05/28 12:11:48 by hdezier           #+#    #+#             //
//   Updated: 2015/06/10 15:49:56 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef RULES_HPP
# define RULES_HPP

# include "Player.hpp"
# include "Board.hpp"

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

	static void			reset(void);
	static eValidity	makeMove(Board &b, Player &p1, Player &p2);
//	static eValidity	simulateMove(Board &b, Player::vec2 const &move,
//								Cell::eValue player);
private:
	static Board::sCell const	*_winMove[Cell::E_VALUE];

	Rules(void);
	Rules(Rules const &src);
	~Rules(void);

	Rules			&operator=(Rules const &rhs);

	static int			win(Board const &b, Board::sCell const &cell);
	static bool			insertDoubleFreethrees(Board &b, Board::sCell &cell);
	static bool			canCaptureFive(Board &b, Board::sCell const &cell,
									   int dirWin);
	static eValidity	captureStone(Board &b, Board::sCell &cell,
									 Player &player);
	static bool			canCaptureLast(Board &b, Board::sCell &cell,
									   Player &opponent);
};

#endif
