// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/05/28 12:10:55 by hdezier           #+#    #+#             //
//   Updated: 2015/06/01 18:37:41 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <cstdlib>

# include "Cell.hpp"
class Board;

class Player
{
public:
	struct		vec2
	{
		int		x;
		int		y;
	};

	Player(void);
	~Player(void);

	void			attribPlayer(Cell::eValue e);


	bool			ai(void) const;
	vec2 const		&calculusMove(void) const;

	void			setAI(bool const &ai);
	vec2 const		&play(Board &b, vec2 const &event);

private:
	bool			_ai;
	vec2			_calculusMove;
	Cell::eValue	_e;

	Player(Player const &src);
	Player			&operator=(Player const &rhs);

	vec2 const		&calculus(Board &b);
};

#endif
