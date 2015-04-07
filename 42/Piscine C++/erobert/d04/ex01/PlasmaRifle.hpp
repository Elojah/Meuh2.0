// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PlasmaRifle.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 15:59:48 by erobert           #+#    #+#             //
//   Updated: 2015/01/09 16:00:36 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PLASMA_RIFLE_HPP
# define PLASMA_RIFLE_HPP

# include "AWeapon.hpp"

class PlasmaRifle: public AWeapon
{
public:
	PlasmaRifle(void);
	PlasmaRifle(PlasmaRifle const &pR);
	virtual ~PlasmaRifle(void);

	PlasmaRifle		&operator=(PlasmaRifle const &pR);

	virtual void	attack(void) const;
};

#endif
