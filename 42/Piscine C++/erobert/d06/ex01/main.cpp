// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/13 13:34:12 by erobert           #+#    #+#             //
//   Updated: 2015/01/13 15:18:18 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ex01.h"

int			main(void)
{
	Data	*data;
	void	*ptr;

	std::cout << "---serialize---" << std::endl;
	ptr = serialize();
	std::cout << "void *:" << std::endl
			  << reinterpret_cast<char *>(ptr)
			  << std::endl;
	std::cout << "--deserialize--" << std::endl;
	data = deserialize(ptr);
	std::cout << "s1: " << data->s1 << std::endl;
	std::cout << "n:  " << data->n << std::endl;
	std::cout << "s2: " << data->s2 << std::endl;
	delete static_cast<char *>(ptr);
	delete data;
}
