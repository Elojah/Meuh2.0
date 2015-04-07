// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Unit.class.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: exam <marvin@42.fr>                        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 18:51:36 by exam              #+#    #+#             //
//   Updated: 2015/01/09 19:43:13 by exam             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef UNIT_CLASS_HPP
# define UNIT_CLASS_HPP

# include <string>
# include <iostream>

class Unit
{
protected:
	int			_index;
	std::string	_type;
	int			_x;
	int			_y;
	int			_dam;
	int			_cHP;
	int			_mHP;
	static int	_nb;
public:
	Unit(void);
	Unit(Unit const &u);
	Unit(std::string const &type, int const x, int const y,
		 int const dam, int const cHP, int const mHP);
	~Unit(void);

	Unit				&operator=(Unit const &u);
	Unit				&operator+=(int const i);
	Unit				&operator-=(int const i);

	int					getIndex(void) const;
	std::string const	&getType(void) const;
	int					getX(void) const;
	int					getY(void) const;
	int					getDam(void) const;
	int					getCHP(void) const;
	int					getMHP(void) const;

	void				die(void);
	void				move(int x, int y);
	void				attack(Unit &target) const;
};

std::ostream		&operator<<(std::ostream &os, Unit const &u);

#endif
