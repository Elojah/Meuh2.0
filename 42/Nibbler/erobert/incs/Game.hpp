// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/30 13:22:57 by erobert           #+#    #+#             //
//   Updated: 2015/03/31 15:18:33 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GAME_HPP
# define GAME_HPP

# include <dlfcn.h>
# include <iostream>
# include <list>
# include <sstream>
# include <vector>

# define MIN_SIZE 10
# define MAX_SIZE 80

class IGUINibbler;

class Game
{
public:
	enum eState
	{
		ALIVE,
		DEAD,
		PAUSE
	};
	enum eInput
	{
		ESC,
		UP,
		LEFT,
		DOWN,
		RIGHT,
		F1,
		F2,
		F3
	};
	struct sNibbler
	{
		int				dir;
		int				x;
		int				y;
	};

	Game(void);
	~Game(void);

	bool				buildMap(char *height, char *width);
	void				gameLoop(void);
private:
	typedef IGUINibbler	*(*tGUICreator)(void);

	int					_height;
	int					_width;
	std::vector<int>	_map;
	std::list<sNibbler>	_nibbler;
	void				*_dlHandle;
	tGUICreator			_gC;

	Game(Game const &g);

	Game				&operator=(Game const &g);

	bool				printError(void) const;
	void				printMap(void) const;
};

#endif
