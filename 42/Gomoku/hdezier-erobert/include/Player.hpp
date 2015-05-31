// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/05/28 12:10:55 by hdezier           #+#    #+#             //
//   Updated: 2015/05/31 15:21:39 by erobert          ###   ########.fr       //
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

	bool			ai(void) const;
	vec2 const		&calculusMove(void) const;

	void			setAI(bool const &ai);
	vec2 const		&play(Board const &b, vec2 const &event);
private:
	bool			_ai;
	vec2			_calculusMove;

	Player(Player const &src);

	Player			&operator=(Player const &rhs);

	vec2 const		&calculus(Board const &b);
};

#endif
