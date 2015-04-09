// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Marine.class.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: exam <marvin@42.fr>                        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 20:24:51 by exam              #+#    #+#             //
//   Updated: 2015/01/09 20:46:27 by exam             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MARINE_HPP
# define MARINE_HPP

# include "Unit.class.hpp"

class Marine: public Unit
{
public:
	Marine(void);
	Marine(Marine const &m);
	Marine(int const x, int const y);
	virtual ~Marine(void);

	Marine				&operator=(Marine const &m);

	virtual void		die(void);
	virtual void		move(int x, int y);

	void				stimpack(void);
};

#endif
