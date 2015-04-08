/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbobillo <rbobillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 01:52:46 by rbobillo          #+#    #+#             */
//   Updated: 2015/01/11 19:17:56 by rbobillo         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "ft_retro.h"
# include "Game.hpp"
# include "Ship.hpp"

class Player:
	public Game,
	public Ship
{
public:
	Player(void);
	Player(Player const &p);
	Player(std::string const &name);
	~Player(void);

	Player				&operator=(Player const &p);
	Player				&operator=(Ship const &s);

	std::string	const	&getName(void) const;
	int					getCLives(void) const;
	int					getMLives(void) const;

	virtual void		retriveSpaceObject(t_spaceObject &sO) const;

private:
	std::string			_name;
	int					_cLives;
	int					_mLives;
};

#endif
