// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Pony.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 09:11:21 by erobert           #+#    #+#             //
//   Updated: 2015/01/06 09:47:32 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "Pony.hpp"

Pony::Pony(bool bad):
	_bad(bad)
{
	std::cout << "Pony behaviour save" << std::endl;
	return ;
}
Pony::~Pony(void)
{
	if (this->_bad)
		std::cout << "Bad pony released" << std::endl;
	else
		std::cout << "Nice pony killed" << std::endl;
	return ;
}

bool	Pony::jumpStupid(void)
{
	std::cout << "Jump stupid" << std::endl;
	return (!this->_bad);
}
