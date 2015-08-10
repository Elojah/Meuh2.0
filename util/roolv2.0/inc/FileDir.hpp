/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileDir.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 11:21:57 by leeios            #+#    #+#             */
/*   Updated: 2015/08/10 22:10:54 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_DIR_HPP
# define FILE_DIR_HPP

# include <string>

namespace utils {
	bool	makeFolderTree(std::string const &schema, std::string const &path);
	bool	touchFile(std::string const &origin, std::string const &dest);
}

#endif
