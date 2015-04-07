// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   DateTime.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/17 16:39:09 by erobert           #+#    #+#             //
//   Updated: 2015/01/17 17:10:15 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "DateTime.hpp"
#include <iostream>
#include <ctime>
DateTime::DateTime(void):
	_title("Date & time"),
	_type(IMonitorModule::STRING)
{
/*	FILE		*pipe(popen("date +'%y-%m-%d'", "r"));
    char		buffer[128];
	std::string	date("");
	std::string	time("");

	if (pipe)
	{
		while(!feof(pipe))
		{
			if(fgets(buffer, 128, pipe))
				date += buffer;
		}
		pclose(pipe);
		_info["Date (yy-mm-dd)"] = date;
	}
	pipe = popen("uname -r", "r");
	if (pipe)
	{
		while(!feof(pipe))
		{
			if(fgets(buffer, 128, pipe))
				time += buffer;
		}
		pclose(pipe);
		_info["Time (hh:mm::ss)"] = time;
	}
	time_t t = std::time(0);   // get time now
    struct tm * now = localtime( & t );
	std::cout << (now->tm_year + 1900) << '-' 
			  << (now->tm_mon + 1) << '-'
			  <<  now->tm_mday
			  <<  now->tm_min
			  << std::endl;*/

}
DateTime::~DateTime(void) {}

std::string const					&DateTime::getTitle(void) const
{
	return (_title);
}
int									DateTime::getType(void) const
{
	return (_type);
}
std::map<std::string, std::string>	DateTime::getInfo(void)
{
	time_t							t(std::time(0));
    struct tm						*now(localtime(&t));
	std::stringstream				date;
	std::stringstream				time;

	date << (now->tm_year + 1900) << '-' 
		 << (now->tm_mon + 1) << '-'
		 <<  now->tm_mday
		 << std::endl;
	_info["Date (yy-mm-dd)"] = date.str();
	time <<  now->tm_hour << ":";
	if (now->tm_min < 10)
		time << "0";
	time << now->tm_min << ":";
	if (now->tm_sec < 10)
		time << "0";
	time << now->tm_sec
		 << std::endl;
	_info["Time (hh:mm:ss)"] = time.str();
	return (_info);
}
