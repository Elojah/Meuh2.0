// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Enemy.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 14:07:19 by erobert           #+#    #+#             //
//   Updated: 2015/01/09 15:25:03 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <string>

class Enemy
{
protected:
	int			_hp;
	std::string	_type;

public:
	Enemy(void);
	Enemy(Enemy const &e);
	Enemy(int hp, std::string const &type);
	virtual ~Enemy(void);

	Enemy				&operator=(Enemy const &e);

	int					getHP() const;	
	std::string	const	&getType(void) const;

	virtual void		takeDamage(int amount);
};

#endif
