// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   OSInfo.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/17 16:20:06 by erobert           #+#    #+#             //
//   Updated: 2015/01/17 16:58:08 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "OSInfo.hpp"

OSInfo::OSInfo(void):
	_title("Operating system"),
	_type(IMonitorModule::STRING)
{
	FILE		*pipe(popen("uname", "r"));
    char		buffer[128];
	std::string	os("");
	std::string	version("");

	if (pipe)
	{
		while(!feof(pipe))
		{
			if(fgets(buffer, 128, pipe))
				os += buffer;
		}
		pclose(pipe);
		_info["OS"] = os;
	}
	pipe = popen("uname -r", "r");
	if (pipe)
	{
		while(!feof(pipe))
		{
			if(fgets(buffer, 128, pipe))
				version += buffer;
		}
		pclose(pipe);
		_info["Version"] = version;
	}
}
OSInfo::~OSInfo(void) {}

std::string const					&OSInfo::getTitle(void) const
{
	return (_title);
}
int									OSInfo::getType(void) const
{
	return (_type);
}
std::map<std::string, std::string>	OSInfo::getInfo(void)
{
	return (_info);
}
