// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   LaserGatling.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 17:24:14 by erobert           #+#    #+#             //
//   Updated: 2015/01/11 19:21:57 by rbobillo         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef LASER_GATLING_HPP
# define LASER_GATLING_HPP

# include "ft_retro.h"
# include "AWeapon.hpp"

class LaserGatling: public AWeapon
{
public:
	LaserGatling(void);
	LaserGatling(LaserGatling const &lG);
	virtual ~LaserGatling(void);

	LaserGatling	&operator=(LaserGatling const &lG);

	virtual void	attack(void) const;
};

#endif
