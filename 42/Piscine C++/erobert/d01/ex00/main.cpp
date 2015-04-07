// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 09:26:56 by erobert           #+#    #+#             //
//   Updated: 2015/01/06 11:55:10 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "Pony.hpp"

static void	ponyOnTheStack(void)
{
	Pony	pony(true);

	pony.jumpStupid();
	std::cout << "ponyOnTheStack end" << std::endl;
}

static void	ponyOnTheHeap(void)
{
	Pony	*pony;

	pony = new Pony(false);
	pony->jumpStupid();
	delete pony;
	std::cout << "ponyOnTheHeap end" << std::endl;
}

int			main(void)
{
	ponyOnTheStack();
	ponyOnTheHeap();
	return (0);
}
