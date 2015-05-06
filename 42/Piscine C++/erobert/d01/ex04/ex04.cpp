// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ex04.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 13:59:27 by erobert           #+#    #+#             //
//   Updated: 2015/01/06 14:07:32 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <string>

int				main(void)
{
	std::string	str("HI THIS IS BRAIN");
	std::string	*strP(&str);
	std::string	&strR(str);

	std::cout << *strP
			  << std::endl
			  << strR
			  << std::endl;
	return (0);
}
