/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileDir.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 12:31:19 by leeios            #+#    #+#             */
/*   Updated: 2015/08/10 22:10:42 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileDir.hpp"
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>

namespace utils {

bool	makeFolderTree(std::string const &schema, std::string const &path) {
	std::ifstream	ifs(("./config/proj_tree/" + schema).c_str());

	if (ifs.fail()) {
		return (false);
	}
	std::string		line;

	if (mkdir(path.c_str(), S_IRWXU) < 0) {
		ifs.close();
		return (false);
	}
	while (std::getline(ifs, line)) {
		if (mkdir((path + "/" + line).c_str(), S_IRWXU) < 0) {
			ifs.close();
			return (false);
		}
	}
	ifs.close();
	return (true);
}

bool	touchFile(std::string const &origin, std::string const &dest) {

	std::ifstream	ifs(origin.c_str());
	std::ofstream	ofs(dest.c_str());
	std::string		line;

	if (ifs.fail() || ofs.fail()) {
		return (false);
	}
	while (std::getline(ifs, line)) {
		ofs << line << std::endl;
	}
	ifs.close();
	ofs.close();
	return (true);
}

} //ns utils
