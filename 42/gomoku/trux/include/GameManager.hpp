// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GameManager.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/05/18 11:07:40 by erobert           #+#    #+#             //
//   Updated: 2015/05/26 15:47:38 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GAME_MANAGER_HPP
# define GAME_MANAGER_HPP

# include "GUIBoard.hpp"
# include "Player.hpp"

class GameManager
{
public:
	enum eSize
	{
		SMALL,
		MEDIUM,
		BIG,
		E_SIZE
	};

	GameManager(void);
	~GameManager(void);

	void				initBoard(eSize size);
	void				gameLoop(void);
private:
	GUIBoard			_gB;
	size_t				_size;
	eCell				_turn;
	bool				_exit;
<<<<<<< HEAD
	GUIBoard::eCell		_board[19][19];
=======
	eCell				_board[19][19];
	Player				_p1;
	Player				_p2;
>>>>>>> 82f5b62da3802cdffdbfc432b6413544d02ec05b

	GameManager(GameManager const &rhs);
	GameManager			operator=(GameManager const &rhs);

	void				eventHandler(void);
	bool				isValidMove(Player::sMove &move);
	void				applyMove(Player::sMove &move);
};

#endif
