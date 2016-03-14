/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 18:22:14 by leeios            #+#    #+#             */
/*   Updated: 2016/03/14 17:14:46 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

#include <fstream>
#include <iostream>

#include "Error.hpp"

#include "IToken.hpp"
#include "Token.hpp"

const size_t		Parser::m_nbToken = (size_t)eTokenType::N_TOKEN_TYPE;
const IToken		*Parser::m_allTokens[(size_t)eTokenType::N_TOKEN_TYPE] =
{
	(const IToken *)new Token<TokensDefinition::sComment>,
	(const IToken *)new Token<TokensDefinition::sPriorities>,
	(const IToken *)new Token<TokensDefinition::sEntity>,
	(const IToken *)new Token<TokensDefinition::sNegation>,
	(const IToken *)new Token<TokensDefinition::sOperator>,
	(const IToken *)new Token<TokensDefinition::sOperand>,
	(const IToken *)new Token<TokensDefinition::sContextMark>,
};

Parser::Parser(void)
{
	;
}

Parser::~Parser(void)
{
	for (auto iToken : m_allTokens)
		delete (iToken);
}

void	Parser::initMask(tok_indexes &mask)
{
	mask.resize(m_nbToken);
	for (size_t i = 0; i < m_nbToken; ++i)
		mask[i] = i;
}

void	Parser::exec(char *filename)
{
	std::ifstream		ifs(filename);
	std::string			line;
	size_t				numLine = 0;
	tok_indexes			mask;
	Parser::initMask(mask);
	std::string			currentToken;
	while (std::getline(ifs, line))
	{
		size_t size = line.size() + 1;
		for (size_t i = 0; i < size; ++i)
		{
			if (currentToken.empty()
				&& (std::isspace(line[i]) || line[i] == '\0'))
				continue ;
			currentToken += line[i];
			// Token was found, so we remove last char. It will be first one of next token
			if (_readToken(mask, currentToken))
				--i;
			if (mask.empty())
			{
				Error::raise_error(eErr::UNRECOGNIZED_SYMBOL
					, std::string("at line: ") + std::to_string(numLine)
					+ std::string("\nat char: ") + std::to_string(i)
					+ '\n' + std::string("symbol: ") + currentToken);
				return ;
			}
		}
		++numLine;
	}
}

bool	Parser::_readToken(tok_indexes &mask, std::string &s)
{
	size_t n = mask.size();
	for (size_t i = 0; i < n; ++i)
	{
		uint8_t		currentToken = mask[i];
		eResponse	resp = m_allTokens[currentToken]->detect(s);

		switch (resp)
		{
			case (eResponse::NONE):
				mask.erase(mask.begin() + i);
				--n;
				--i;
				break ;
			case (eResponse::OK):
				break ;
			case (eResponse::COMPLETE):
				s.pop_back();
				m_resultToken.push_back(m_allTokens[currentToken]->getNewInstance(s));
				m_allTokens[currentToken]->getNextTokens(mask);
				s.clear();
				return (true);
		}
	}
	return (false);
}

#ifdef _DBG_
void	Parser::printResult(void)
{
	std::cerr << "Result:" << std::endl;
	for (auto iToken : m_resultToken)
		iToken->printStr();
}
#endif
