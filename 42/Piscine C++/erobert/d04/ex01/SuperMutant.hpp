// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SuperMutant.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 14:22:32 by erobert           #+#    #+#             //
//   Updated: 2015/01/09 15:30:31 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SUPER_MUTAN_HPP
# define SUPER_MUTAN_HPP

# include <iostream>
# include "Enemy.hpp"

class SuperMutant:
	public Enemy
{
public:
	SuperMutant(void);
	SuperMutant(SuperMutant const &sM);
	virtual ~SuperMutant(void);

	SuperMutant		&operator=(SuperMutant const &sM);

	virtual void	takeDamage(int amount);
};

#endif
