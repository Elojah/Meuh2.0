/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 11:21:57 by leeios            #+#    #+#             */
/*   Updated: 2015/08/13 22:06:30 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_HPP
# define UTIL_HPP

# include <string>
# include <map>
# include <vector>

namespace utils {
	/*File*/
	bool	makeFolderTree(std::string const &schema, std::string const &path);
	bool	touchFile(std::string const &origin, std::string const &dest);
	bool	touchFileVariables(std::string const &origin, std::string const &dest
			, const std::map<std::string, std::string> &map);
	const std::string			duplicateString(std::string const &filename
		, std::vector< std::map < std::string, std::string > > const &vecMap);
	void	addToFile(const std::string &oldName, const std::string &newName
		, const std::string &filePath, bool removeOld);

	/*Str*/
	std::string		parseClassName(std::string const &str);
	std::string		parseGuard(std::string const &str);
	std::vector< std::map < std::string, std::string > >		parseParents(std::string const &str);

}

#endif
