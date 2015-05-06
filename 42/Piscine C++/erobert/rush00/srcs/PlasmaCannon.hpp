// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PlasmaCannon.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 16:21:36 by erobert           #+#    #+#             //
//   Updated: 2015/01/11 19:21:42 by rbobillo         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PLASMA_CANNON_HPP
# define PLASMA_CANNON_HPP

# include "ft_retro.h"
# include "AWeapon.hpp"

class PlasmaCannon: public AWeapon
{
public:
	PlasmaCannon(void);
	PlasmaCannon(PlasmaCannon const &pR);
	virtual ~PlasmaCannon(void);

	PlasmaCannon	&operator=(PlasmaCannon const &pR);

	virtual void	attack(void) const;
};

#endif
