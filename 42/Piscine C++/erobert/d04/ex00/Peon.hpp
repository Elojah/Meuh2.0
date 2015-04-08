// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Peon.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 10:33:14 by erobert           #+#    #+#             //
//   Updated: 2015/01/09 12:03:53 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PEON_HPP
# define PEON_HPP

# include "Victim.hpp"

class Peon:
	public Victim
{
public:
	Peon(void);
	Peon(Peon const &p);
	Peon(std::string const name);
	~Peon(void);

	Peon		&operator=(Peon const &p);

	void		getPolymorphed(void) const;
};

#endif
