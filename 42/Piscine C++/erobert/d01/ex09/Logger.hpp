// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Logger.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 20:19:05 by erobert           #+#    #+#             //
//   Updated: 2015/01/06 20:39:25 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <sstream>
# include <sys/time.h>

class Logger
{
private:
	std::string	_output;

	void		logToFile(std::string const &message);
	void		logToConsole(std::string const &message);
	std::string	makeLogEntry(std::string const &message);

public:
	typedef void(Logger::*logger_f) (std::string const &);

	void	log(std::string const & dest, std::string const & message);
};

#endif
