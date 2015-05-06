// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RadScorpion.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 14:42:53 by erobert           #+#    #+#             //
//   Updated: 2015/01/09 15:43:51 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "RadScorpion.hpp"

RadScorpion::RadScorpion(void):
	Enemy(80, "RadScorpion")
{
	std::cout << "* click click click *"
			  << std::endl;
}
RadScorpion::RadScorpion(RadScorpion const &rS):
	Enemy(rS)
{
	std::cout << "* click click click *"
			  << std::endl;
}
RadScorpion::~RadScorpion(void)
{
	std::cout << "* SPROTCH *"
			  << std::endl;
}
