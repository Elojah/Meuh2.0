// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/30 13:22:57 by erobert           #+#    #+#             //
//   Updated: 2015/04/07 18:53:18 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GAME_HPP
# define GAME_HPP

# include <dlfcn.h>
# include <iostream>
# include <list>
# include <sstream>
# include <unistd.h>
# include <vector>

# define MIN_SIZE 10
# define MAX_SIZE 80

class IGUINibbler;

class Game
{
public:
	enum eInput
	{
		F1 = 0,
		F2,
		F3,
		PAUSE,
		RESTART,
		EXIT,
		UP,
		LEFT,
		DOWN,
		RIGHT,
		E_INPUT
	};
	enum eState
	{
		ALIVE,
		DEAD
	};
	enum eObject
	{
		EMPTY,
		WALL,
		APPLE,
		HEAD,
		BODY
	};
	struct sNibbler
	{
		eState			state;
		int				dir;
		int				x;
		int				y;
	};

	Game(void);
	~Game(void);

	bool				buildMap(char *height, char *width);
	void				gameLoop(void);
private:
	typedef IGUINibbler			*(*tGUICreator)(void);
	typedef void				(*tGUIDestructor)(IGUINibbler *gN);
	typedef std::list<sNibbler>	tNibbler;

	int					_height;
	int					_width;
	std::vector<int>	_map;
	tNibbler			_nibbler;
	void				*_dlHandle[3];
	IGUINibbler         *_gN[3];

	Game(Game const &g);

	Game				&operator=(Game const &g);

	void				initNibbler(void);
	int					initDL(void);
	void				closeDL(void);
	void				createGUI(int gui);
	void				destroyGUI(int gui);

	int					newApple(void);
	void				moveNibbler(eInput input);
	bool				eatApple(int apple);
	bool				isDead(void);

	bool				printError(void) const;
	void				printMap(void) const;
};

#endif
