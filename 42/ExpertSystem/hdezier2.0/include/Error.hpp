/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 12:08:55 by leeios            #+#    #+#             */
/*   Updated: 2016/03/20 18:05:40 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_HPP
# define ERR_HPP

#include <iostream>

enum class	eErr
{
	NONE = 0,
	FATAL
};

namespace	err
{
	inline eErr	raise_error(eErr err, const std::string &msg)
	{
		if (err != eErr::NONE)
			std::cerr << msg << std::endl;
		return (err);
	}
};

#endif
