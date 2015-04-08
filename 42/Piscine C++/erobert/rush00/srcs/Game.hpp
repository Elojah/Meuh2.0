// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rbobillo <rbobillo@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 01:56:47 by rbobillo          #+#    #+#             //
/*   Updated: 2015/01/11 20:16:22 by rbobillo         ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#ifndef GAME_HPP
# define GAME_HPP

#include <iostream>
#include <ncurses.h>

class Game
{
public:
	Game(void);
	Game(Game const &g);
	Game(int const pAmount);
	~Game(void);

	Game			&operator=(Game const &g);

	int				getPAmount(void) const;
	void			setLevel(int const level);
	int				getLevel(void) const;
	void			setDifficulty(int const difficulty);
	int				getDifficulty(void) const;

private:
	int				_pAmount;		// Players Amount
	int				_level;
	int				_difficulty;
};

#endif
