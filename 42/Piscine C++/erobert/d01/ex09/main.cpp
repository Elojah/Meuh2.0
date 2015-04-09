// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 20:33:51 by erobert           #+#    #+#             //
//   Updated: 2015/01/06 20:39:40 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "Logger.hpp"

int			main(void)
{
	Logger l;

	l.log("logToFile", "file0");
	l.log("logToFile", "file1");
	l.log("logToConsole", "console0");
	l.log("logToConsole", "console1");

}
