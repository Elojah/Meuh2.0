/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IToken.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 18:16:02 by leeios            #+#    #+#             */
/*   Updated: 2016/03/14 17:14:43 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_TOKEN_HPP
# define I_TOKEN_HPP

#include <string>
#include <iostream>
#include <vector>

enum class		eTokenType
{
	COMMENT = 0,
	PRIORITIES,
	ENTITY,
	NEGATION,
	OPERATOR,
	OPERAND,
	CONTEXTMARK,
	N_TOKEN_TYPE
};

typedef std::vector<uint8_t>	tok_indexes;

enum class eResponse
{
	NONE,
	OK,
	COMPLETE
};

class IToken
{
public:
	virtual ~IToken(void) {};
	virtual eResponse		detect(const std::string &str) const = 0;
	virtual void			getNextTokens(tok_indexes &mask) const = 0;
	virtual IToken			*getNewInstance(const std::string &s) const = 0;
	virtual void			setStr(const std::string &s) = 0;
	virtual void			printStr(void) const = 0;
};

#endif
