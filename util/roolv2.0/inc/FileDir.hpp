/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileDir.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 11:21:57 by leeios            #+#    #+#             */
/*   Updated: 2015/07/19 11:33:03 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_DIR_HPP
# define FILE_DIR_HPP

# include <string>

namespace utils {
	bool	makeFolderTree(std::string const &schema, std::string const &path);
}

#endif
