/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FtFile.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 12:31:19 by leeios            #+#    #+#             */
/*   Updated: 2015/08/13 21:28:19 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.hpp"
#include <sstream>
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

bool	touchFileVariables(std::string const &origin, std::string const &dest
		, const std::map<std::string, std::string> &map) {
	std::ifstream		ifs(origin);
	std::ofstream		ofs(dest);
	std::string			line;

	if (ifs.fail() || ofs.fail()) {
		return (false);
	}
	while (std::getline(ifs,line)) {
		for (const auto i : map) {
			size_t found(0);

			while ((found = line.find(i.first, found)) != std::string::npos) {
				line.replace(found, i.first.length(), i.second);
				found++;
			}
		}
		ofs << line << std::endl;
	}
	ifs.close();
	ofs.close();
	return (true);
}

const std::string			duplicateString(std::string const &filename
	, std::vector< std::map < std::string, std::string > > const &vecMap) {
	std::ifstream		ifs(filename);

	if (vecMap.empty() || ifs.fail()) {
		return ("");
	}
	std::string				result;
	std::stringstream	buffer;

	buffer << ifs.rdbuf();
	for (const auto i : vecMap) {
		std::string line(buffer.str());

		for (const auto s : i) {
			size_t found(0);

			while ((found = line.find(s.first, found)) != std::string::npos) {
				line.replace(found, s.first.length(), s.second);
				found++;
			}
		}
		result += line;
	}
	return (result);
}

} //ns utils
