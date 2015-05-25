// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GameManager.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/05/18 11:07:40 by erobert           #+#    #+#             //
//   Updated: 2015/05/25 16:51:12 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GAME_MANAGER_HPP
# define GAME_MANAGER_HPP

# include "GUIBoard.hpp"

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

	enum eCell
	{
		EMPTY,
		P1,
		P2
	};

	GameManager(void);
	~GameManager(void);

	void				initBoard(eSize size);
	void				gameLoop(void);
private:

	GUIBoard			_gB;
	size_t				_size;
	bool				_turn;
	bool				_exit;
	eCell				_board[19][19];

	GameManager(GameManager const &rhs);

	GameManager			operator=(GameManager const &rhs);

	void				eventHandler(void);
};

#endif
