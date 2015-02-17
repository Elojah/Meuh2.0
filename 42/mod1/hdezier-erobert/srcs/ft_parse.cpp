// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ft_parse.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/02/08 14:00:20 by erobert           #+#    #+#             //
//   Updated: 2015/02/08 15:07:55 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <string.h>
#include "IObject.hpp"
#include "UserInterface.hpp"
#include "Landscape.hpp"
#include "Parser.hpp"

int					main(int ac ,char **av)
{
	UserInterface	uI(av[0]);
	IObject			*landscape;
	float			**tab;
	Parser			parseObject;

	(void)ac;
	parseObject.parseFile(av[1]);
	// parseObject.printArray();
	tab = parseObject.getArray();
	landscape = new Landscape(tab, 500, 500);
	uI.addObject(landscape);
	uI.drawLoop();
	return (0);
}
