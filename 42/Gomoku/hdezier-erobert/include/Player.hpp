// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/05/28 12:10:55 by hdezier           #+#    #+#             //
//   Updated: 2015/06/05 19:01:21 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <cstdlib>
# include <iostream>
# include "Cell.hpp"

class Board;

class Player
{
public:
	struct sAttribute
	{
		bool		ai;
		bool		turn;
		bool		win;
		int			x;
		int			y;
		int			captured;
	};
	struct vec2
	{
		int		x;
		int		y;
	};

	Player(void);
	~Player(void);

	sAttribute const	&attribute(void) const;
	vec2 const			&calculusMove(void) const;

	void				switchAI(void);
	void				switchTurn(void);
	void				switchWin(void);
	void				addCapture(int n);
	bool				play(Board &b, Player::vec2 const &move);
	void				calculus(Board &b);
private:
	sAttribute			_attribute;
	vec2				_calculusMove;
	Cell::eValue		_e;

	Player(Player const &src);
	Player				&operator=(Player const &rhs);
};

#endif
