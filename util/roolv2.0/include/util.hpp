/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 11:21:57 by leeios            #+#    #+#             */
/*   Updated: 2015/08/13 16:53:04 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_HPP
# define UTIL_HPP

# include <string>
# include <map>

namespace utils {
	/*File*/
	bool	makeFolderTree(std::string const &schema, std::string const &path);
	bool	touchFile(std::string const &origin, std::string const &dest);
	bool	touchFileVariables(std::string const &origin, std::string const &dest
			, std::map<std::string, std::string> map);

	/*Str*/
	std::string		parseClassName(std::string const &str);
	std::string		parseGuard(std::string const &str);
	std::string		parseParents(std::string const &str);
	std::string		parsePrevName(std::string const &str);
	std::string		parseNewName(std::string const &str);
}

#endif
