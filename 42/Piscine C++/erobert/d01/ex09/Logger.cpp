// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Logger.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 20:22:47 by erobert           #+#    #+#             //
//   Updated: 2015/01/06 20:39:52 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Logger.hpp"

void		Logger::logToConsole(std::string const &message)
{
	std::cout << makeLogEntry(message);
}
void		Logger::logToFile(std::string const &message)
{
	std::ofstream	ofs;

	ofs.open("file.log", std::ios_base::app);
	ofs << makeLogEntry(message);
}
std::string	Logger::makeLogEntry(std::string const &message)
{
	std::stringstream	ss;
	struct timeval		tp;

	gettimeofday(&tp, NULL);
	ss << "["
	   << tp.tv_sec
	   << "_" 
	   << tp.tv_usec
	   << "] "
	   << message
	   << std::endl;
	return (ss.str());
}

void		Logger::log(std::string const &dest, std::string const &message)
{
	logger_f	a[2] = {
		&Logger::logToFile,
		&Logger::logToConsole,
	};
	std::string	names[2] = {
		"logToFile",
		"logToConsole",
	};
	int			i(-1);

	while (++i < 3)
	{
		if (!dest.compare(names[i]))
			(this->*a[i])(message);
	}
}
