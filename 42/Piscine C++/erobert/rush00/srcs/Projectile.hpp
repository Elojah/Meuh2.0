// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Projectile.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/11 10:48:35 by erobert           #+#    #+#             //
//   Updated: 2015/01/11 20:34:38 by rbobillo         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PROJECTILE_HPP
# define PROJECTILE_HPP

# include <iostream>
# include "ft_retro.h"
# include "Ship.hpp"
# include "Player.hpp"
# include "Projectile.hpp"

class Projectile: public ISpaceObject
{
private:
	int				_dir;
	int				_pos[2];

public:
	Projectile(void);
	Projectile(Projectile const &p);
	Projectile(Ship const &s);
	Projectile(Player const &p);
	~Projectile(void);

	Projectile		&operator=(Projectile const &p);

	int				getDir(void) const;
	int				*getPos(void) const;

	virtual void	retriveSpaceObject(t_spaceObject &sO) const;
};

std::ostream		&operator<<(std::ostream &os, Projectile const &p);

#endif
