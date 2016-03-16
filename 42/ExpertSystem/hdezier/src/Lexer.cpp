/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:42:05 by leeios            #+#    #+#             */
/*   Updated: 2016/03/16 11:11:22 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.hpp"
#include <iostream>

Lexer::Lexer(void)
{
	;
}

Lexer::~Lexer(void)
{
	;
}

void	Lexer::addToken(const std::string &token, eTokenType type)
{
	(void)token;
	switch (type)
	{
		case (eTokenType::COMMENT) :
		break ;
		case (eTokenType::PRIORITIES) :
		break ;
		case (eTokenType::ENTITY) :
		break ;
		case (eTokenType::NEGATION) :
		break ;
		case (eTokenType::OPERATOR) :
		break ;
		case (eTokenType::OPERAND) :
		break ;
		case (eTokenType::CONTEXTMARK) :
		break ;
		default :
			std::cerr << "Token type doesn't exist" << std::endl;
		break ;
	}
}
