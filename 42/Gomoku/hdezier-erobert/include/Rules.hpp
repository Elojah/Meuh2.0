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

	enum eValidity
	{
		INVALID = 0,
		OK,
		WIN
	};

	static eValidity	makeMove(Board &b, Player::vec2 const &move,
							 Cell::eValue const &player);
	static void			captureStone(Cell &cell);
private:
	Rules(void);
	~Rules(void);
	Rules(Rules const &src);
	Rules			&operator=(Rules const &rhs);

	static bool		win(Cell &cell);
};

#endif
