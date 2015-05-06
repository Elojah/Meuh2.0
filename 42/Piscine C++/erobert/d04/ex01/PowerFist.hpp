// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PowerFist.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 14:03:11 by erobert           #+#    #+#             //
//   Updated: 2015/01/09 15:59:12 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef POWER_FIST_HPP
# define POWER_FIST_HPP

# include "AWeapon.hpp"

class PowerFist: public AWeapon
{
public:
	PowerFist(void);
	PowerFist(PowerFist const &pF);
	virtual ~PowerFist(void);

	PowerFist		&operator=(PowerFist const &pF);

	virtual void	attack(void) const;
};

#endif
