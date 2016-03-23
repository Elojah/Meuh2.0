/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:42:05 by leeios            #+#    #+#             */
/*   Updated: 2016/03/16 11:11:17 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_HPP
# define LEXER_HPP

#include "IToken.hpp"
#include "IExpr.hpp"

class Lexer
{
public:
	Lexer(void);
	virtual ~Lexer(void);
	void	addToken(const std::string &token, eTokenType type);
protected:
private:
	std::vector<IExpr *>	m_rules;
};

#endif
