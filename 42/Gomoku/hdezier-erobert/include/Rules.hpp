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
	Rules(void);
	~Rules(void);

	static bool		makeMove(Board &b, Player::vec2 const &move,
							 Cell::eValue const &player);
private:
	Rules(Rules const &src);

	Rules			&operator=(Rules const &rhs);
};

#endif
