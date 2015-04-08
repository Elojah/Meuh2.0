// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RadScorpion.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 14:41:14 by erobert           #+#    #+#             //
//   Updated: 2015/01/09 15:30:15 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef RAD_SCORPION_HPP
# define RAD_SCORPION_HPP

# include <iostream>
# include "Enemy.hpp"

class RadScorpion:
	public Enemy
{
public:
	RadScorpion(void);
	RadScorpion(RadScorpion const &rS);
	virtual ~RadScorpion(void);

	RadScorpion		&operator=(RadScorpion const &rS);
};

#endif
