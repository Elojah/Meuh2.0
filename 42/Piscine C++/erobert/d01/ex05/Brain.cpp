// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Brain.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 14:22:45 by erobert           #+#    #+#             //
//   Updated: 2015/01/06 15:55:48 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Brain.hpp"

Brain::Brain(void)
{
	return ;
}
Brain::~Brain(void)
{
	return ;
}

std::string	Brain::identify(void) const
{
	std::stringstream	ss;

	ss << this;
	return (ss.str());
}

void		Brain::thinkDonuts(void)
{
	std::cout << "Mmmm donuts.."
			  << std::endl;
}
