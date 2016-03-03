/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 18:03:58 by leeios            #+#    #+#             */
/*   Updated: 2016/03/03 18:25:23 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HPP
# define ERROR_HPP

#include <string>

enum class	eErr
{
	NOT_ENOUGH_ARGS,
	CANT_READ_FILE,
	UNRECOGNIZED_SYMBOL,
	NO_ERR
};

class Error
{
public:
	Error(void);
	virtual ~Error(void);
	static bool			raise_error(const eErr err, const std::string &details);
protected:
private:
	const static char	*m_errMsgs[];
};

#endif
