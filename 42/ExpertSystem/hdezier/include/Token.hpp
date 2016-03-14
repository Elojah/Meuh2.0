/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 22:26:33 by leeios            #+#    #+#             */
/*   Updated: 2016/03/14 17:20:01 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_HPP
# define TOKEN_HPP

# include "specialization.h"
# include "IToken.hpp"
# include "TokensDefinition.hpp"
# include "Parser.hpp"

# include <string>
# include <iostream>

template<typename TokenDef>
class Token : public IToken
{
public:
	Token(void) = default;
	virtual ~Token(void) = default;

	virtual void			getNextTokens(tok_indexes &mask) const override {Parser::initMask(mask);};
	virtual IToken			*getNewInstance(const std::string &s) const override
	{
		Token<TokenDef>		*result;
		result = new Token<TokenDef>;
		result->setStr(s);
		return (result);
	};
	virtual void			setStr(const std::string &s) override {m_str = s;};
	virtual void			printStr(void) const override {std::cout << m_str << std::endl;};

protected:
private:

	std::string		m_str;

	DECL_INIT(0, spe_none, TokenDef)
	DECL_SPE(1, spe_detect, detect)
	DECL_SPE(2, spe_words, words)

	/*
	**
	** Detect implementations
	**
	*/

	/*
	** Words attribute
	*/
	template<typename T>
	static eResponse	_detect_impl(const std::string &readToken, spe_words)
	{
		size_t		readSize = readToken.size();
		for (const auto word : T::words)
		{
			size_t	sizeToCompare = std::min(readSize, word.size());
			if (word.compare(0, sizeToCompare, readToken.c_str(), sizeToCompare) == 0)
			{
				if (readSize > word.size())
					return (eResponse::COMPLETE);
				else
					return (eResponse::OK);
			}
		}
		return (eResponse::NONE);
	};

	/*
	** Detect method
	*/
	template<typename T>
	static eResponse	_detect_impl(const std::string &readToken, spe_detect)
	{
		return (T::detect(readToken));
	};

	/*
	** Default fallback
	*/
	template<typename T>
	static eResponse	_detect_impl(const std::string &readToken, spe_none)
	{
		(void)readToken;
		std::cerr << "Class:Token | Call to detect function: Template error | No specialization available." << std::endl;
		return (eResponse::NONE);
	};
	/*
	**
	**!Detect implementations
	**
	*/

public:
	virtual eResponse	detect(const std::string &readToken) const override
	{
		return (_detect_impl<TokenDef>(readToken, _specialization));
	};
};

#endif
