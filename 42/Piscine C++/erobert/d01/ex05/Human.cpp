// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Human.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 14:28:18 by erobert           #+#    #+#             //
//   Updated: 2015/01/06 15:57:23 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Human.hpp"

Human::Human(void)
{
	return ;
}
Human::~Human(void)
{
	return ;
}

Brain const	&Human::getBrain(void)
{
	Brain const	&br(_b);

	return (br);
}

std::string	Human::identify(void)
{
	return (this->_b.identify());
}
