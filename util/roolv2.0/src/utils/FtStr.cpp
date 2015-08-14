/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FtStr.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/13 16:09:05 by leeios            #+#    #+#             */
/*   Updated: 2015/08/14 19:25:49 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.hpp"
#include <stdlib.h>
#include <strings.h>
#include <cstring>

namespace utils {

	std::string		parseClassName(std::string const &str) {
		std::size_t	found;
		std::string	name;

		if ((found = str.find_last_of('/')) != std::string::npos) {
			name = str.substr(found + 1, str.length() - found - 1);
		} else {
			name = str;
		}
		if ((found = name.find(':')) != std::string::npos) {
			std::string	toTrim(name.substr(0, found));
			return (toTrim.erase(toTrim.find_last_not_of(" ") + 1));
		}
		return (name);
	}

	std::string		parseDirectories(std::string const &str) {
		std::size_t	found;

		if ((found = str.find_last_of('/')) != std::string::npos) {
			return(str.substr(0, found));
		} else {
			return ("");
		}
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

	std::vector< std::map < std::string, std::string > >		parseParents(std::string const &str) {
		std::size_t	found;
		std::vector<std::map<std::string, std::string> >	result;

		if ((found = str.find(':')) == std::string::npos) {
			return (result);
		}

		char																							*pch;
		char																							*toFree;
		std::map<std::string, std::string>								tmp;

		toFree = strdup(str.substr(found + 1).c_str());
		pch = std::strtok(toFree,",");
		while (pch != NULL) {
			std::string		line(pch);
			size_t				found(line.find_first_not_of(' '));
			std::size_t		foundEnd(line.find(' ', found));

			if (found == std::string::npos) {
				pch = std::strtok(NULL,",");
				continue ;
			} else if (foundEnd == std::string::npos) {
				tmp["${PERMISSION}"] = "public";
			} else {
				tmp["${PERMISSION}"] = line.substr(found, foundEnd - found);
				found = line.find_first_not_of(' ', foundEnd);
			}
			tmp["${NAME}"] = line.substr(found, line.find(' ', found) - found);
			result.push_back(std::map<std::string, std::string>(tmp));
			tmp.clear();
			pch = std::strtok(NULL,",");
		}
		free(toFree);

		return (result);
	}

} // ns utils
