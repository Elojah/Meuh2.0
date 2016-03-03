/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 18:04:47 by leeios            #+#    #+#             */
/*   Updated: 2016/03/03 18:25:27 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Error.hpp"
#include <iostream>

const char *Error::m_errMsgs[] =
{
	"Not enough argument",
	"Can't read file",
	"Unrecognized symbol",
	"NO ERROR"
};

Error::Error(void)
{
	;
}

Error::~Error(void)
{
	;
}

bool		Error::raise_error(const eErr err, const std::string &details)
{
	unsigned int	err_uint = (unsigned int)err;
	if (err_uint >= (unsigned int)eErr::NO_ERR)
		return (false);
	std::cerr << m_errMsgs[err_uint] << std::endl;
	std::cerr << details << std::endl;
	return (true);
}
