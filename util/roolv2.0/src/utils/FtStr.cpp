/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FtStr.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/13 16:09:05 by leeios            #+#    #+#             */
/*   Updated: 2015/08/13 16:29:55 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.hpp"
#include <stdlib.h>
#include <strings.h>
#include <cstring>

namespace utils {

	std::string		parseClassName(std::string const &str) {
		std::size_t	found;

		if ((found = str.find(':')) != std::string::npos) {
			return (str.substr(0, found));
		}
		return (str);
	}

	std::string		parseGuard(std::string const &str) {
		std::string							result;
		const std::string				tmp(parseClassName(str));

		for (std::string::size_type i = 0; i < tmp.size(); ++i)
		{
			if (tmp[i] >= 'A' && tmp[i] <= 'Z' && i != 0)
				result.push_back('_');
			result.push_back(std::toupper(tmp[i]));
		}
		return (result);
	}

	std::string		parseParents(std::string const &str) {
		std::size_t	found;

		if ((found = str.find(':')) != std::string::npos) {
			return (str.substr(found + 1));
		}
		return (std::string());
	}

	std::string		parsePrevName(std::string const &str) {
		std::size_t	found;

		if ((found = str.find("${PREV_NAME=")) != std::string::npos) {
			found += 12;/*HARDCODE*/
			return (str.substr(found, str.find('}', found) - found));
		}
		return ("");
	}

	std::string		parseNewName(std::string const &str) {
		std::size_t	found;

		if ((found = str.find("${NEW_NAME=")) != std::string::npos) {
			found += 11;/*HARDCODE*/
			return (str.substr(found, str.find('}', found) - found));
		}
		return ("");
	}

} // ns utils
