// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/05/28 12:10:55 by hdezier           #+#    #+#             //
//   Updated: 2015/05/28 12:11:40 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PLAYER_HPP
# define PLAYER_HPP

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

	const vec2		&play(Board const &b, vec2 const &event);
	const vec2		&calculus(Board const &b);
private:
	bool			_ia;
	vec2			_calculusMove;

	Player(Player const &src);

	Player			&operator=(Player const &rhs);
};

#endif
