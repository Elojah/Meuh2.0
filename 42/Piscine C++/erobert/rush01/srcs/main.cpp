// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/17 15:04:18 by erobert           #+#    #+#             //
//   Updated: 2015/01/17 17:00:37 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "IMonitorModule.hpp"
#include "UserInfo.hpp"
#include "OSInfo.hpp"
#include "DateTime.hpp"

int										main(void)
{
	UserInfo							uI;
	OSInfo								oS;
	DateTime							dT;
	std::map<std::string, std::string>	info;

	info = uI.getInfo();
	std::cout << info["Username"];
	std::cout << info["Hostname"];
	info = oS.getInfo();
	std::cout << info["OS"];
	std::cout << info["Version"];
	info = dT.getInfo();
	std::cout << info["Date (yy-mm-dd)"];
	std::cout << info["Time (hh:mm:ss)"];
	return (0);
}
