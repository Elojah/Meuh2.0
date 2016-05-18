/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 16:50:17 by leeios            #+#    #+#             */
/*   Updated: 2016/05/17 18:27:01 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "Tokens.h"
# include <string>

class Stack;

class Lexer
{
public:

	enum class		eResult
	{
		ERR = 0,
		OK,
		QUIT
	};

	Lexer(void) = default;
	virtual ~Lexer(void) = default;
	static eResult		read_line(const std::string &line, Stack &stack);
private:
	static eToken		_analyzeType(const std::string &line);
	static bool			_setElem(lexOperations::sElem &elem, const std::string &line);
};

#endif
