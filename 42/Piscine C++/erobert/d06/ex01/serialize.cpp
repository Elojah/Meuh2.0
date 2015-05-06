// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   serialize.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/13 13:40:03 by erobert           #+#    #+#             //
//   Updated: 2015/01/13 15:46:46 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <cstdlib>
#include <ctime>
#include "ex01.h"

void			*serialize(void)
{
	char		*data = new char[20];
	char const	alphanum[] = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	t_u0		n;
	int			i(-1);

	std::srand(clock());
	n.n = std::rand();
	if (std::rand() % 2)
		n.n *= -1;
	while (++i < 16)
	{
		if (i < 8)
			data[i] = alphanum[std::rand() % 62];
		else
			data[i + 4] = alphanum[std::rand() % 62];
	}
	data[8] = n.s[3];
	data[9] = n.s[2];
	data[10] = n.s[1];
	data[11] = n.s[0];
	return (static_cast<void *>(data));
}
