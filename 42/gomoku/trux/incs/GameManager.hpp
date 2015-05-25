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

# include "SFML/Graphics.hpp"

# define CELL_SIZE 20

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
	size_t				_width;
	size_t				_height;
	size_t				_size;
	sf::RenderWindow	_window;
	sf::Event			_event;
	bool				_exit;

	GameManager(GameManager const &rhs);

	GameManager			operator=(GameManager const &rhs);

	void				eventHandler(void);
};

#endif
