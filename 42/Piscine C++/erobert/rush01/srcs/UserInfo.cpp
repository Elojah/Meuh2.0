// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   UserInfo.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/17 14:51:45 by erobert           #+#    #+#             //
//   Updated: 2015/01/17 16:57:10 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "UserInfo.hpp"

UserInfo::UserInfo(void):
	_title("Hostname/Username"),
	_type(IMonitorModule::STRING)
{
	FILE		*pipe(popen("hostname", "r"));
    char		buffer[128];
	std::string	hostname("");
	std::string	username("");

	if (pipe)
	{
		while(!feof(pipe))
		{
			if(fgets(buffer, 128, pipe))
				hostname += buffer;
		}
		pclose(pipe);
		_info["Hostname"] = hostname;
	}
	pipe = popen("id -u -n", "r");
	if (pipe)
	{
		while(!feof(pipe))
		{
			if(fgets(buffer, 128, pipe))
				username += buffer;
		}
		pclose(pipe);
		_info["Username"] = username;
	}
}
UserInfo::~UserInfo(void) {}

std::string const					&UserInfo::getTitle(void) const
{
	return (_title);
}
int									UserInfo::getType(void) const
{
	return (_type);
}
std::map<std::string, std::string>	UserInfo::getInfo(void)
{
	return (_info);
}
