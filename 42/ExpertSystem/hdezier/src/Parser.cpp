/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 18:22:14 by leeios            #+#    #+#             */
/*   Updated: 2016/03/03 21:18:35 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

#include <fstream>
#include <iostream>

#include "Error.hpp"
#include "IToken.hpp"
#include "TComment.hpp"
#include "TEntity.hpp"

const size_t		Parser::m_nbToken = (size_t)eTokenType::N_TOKEN_TYPE;
const IToken		*Parser::m_allTokens[(size_t)eTokenType::N_TOKEN_TYPE] =
{
	(const IToken *)new TComment,
	(const IToken *)new TEntity
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
	tok_indexes		mask;
	Parser::initMask(mask);
	std::string		currentToken;
	while (std::getline(ifs, line))
	{
		size_t size = line.size() + 1;
		for (size_t i = 0; i < size; ++i)
		{
			currentToken += line[i];
			if (currentToken.empty())
				continue ;
			_readToken(mask, currentToken);
			if (mask.empty())
			{
				Error::raise_error(eErr::UNRECOGNIZED_SYMBOL
					, std::string("at line: ") + std::to_string(i)
					+ '\n' + std::string("symbol: ") + currentToken);
				return ;
			}
		}
	}
}

void	Parser::_readToken(tok_indexes &mask, std::string &s)
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
				break ;
			case (eResponse::OK):
				break ;
			case (eResponse::COMPLETE):
				m_resultToken.push_back(m_allTokens[currentToken]->getNewInstance(s));
				m_allTokens[currentToken]->getNextTokens(mask);
				s.clear();
				break ;
		}
	}
}

#ifdef _DBG_
void	Parser::printResult(void)
{
	std::cerr << "Result:" << std::endl;
	for (auto iToken : m_resultToken)
		iToken->printStr();
}
#endif
