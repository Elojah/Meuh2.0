/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 18:21:58 by leeios            #+#    #+#             */
/*   Updated: 2016/03/16 09:24:42 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
# define PARSER_HPP

#include "IToken.hpp"
#include "Lexer.hpp"

class Parser
{
public:
	Parser(void);
	virtual ~Parser(void);
	void	exec(char *filename);
	static void				initMask(tok_indexes &mask);
	void					setLexer(Lexer &lex);
	#ifdef _DBG_
		void	printResult(void);
	#endif
protected:
private:
	static const size_t		m_nbToken;
	static const IToken		*m_allTokens[(size_t)eTokenType::N_TOKEN_TYPE];
	Lexer					*m_lex;

	bool					_readToken(tok_indexes &mask, std::string &s);
};

#endif
