// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GameManager.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/05/28 12:09:51 by hdezier           #+#    #+#             //
//   Updated: 2015/06/01 18:39:10 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GAME_MANAGER_HPP
# define GAME_MANAGER_HPP

# include "Board.hpp"
# include "Player.hpp"
# include "UserInterface.hpp"
# include "AudioManager.hpp"

class GameManager
{
public:
	GameManager(void);
	~GameManager(void);

	void				init(unsigned int size);
	void				loop(void);
	const Player::vec2	&eventHandler(void);
private:
	Board			_b;
	Player			_p1;
	Player			_p2;
	UserInterface	_ui;
	AudioManager	_audio;
	Cell::eValue	_turn;
	bool			_exit;

	GameManager(GameManager const &src);

	GameManager			&operator=(GameManager const &rhs);
};

#endif
