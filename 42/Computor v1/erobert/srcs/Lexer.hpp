// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Lexer.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/05 17:09:39 by erobert           #+#    #+#             //
//   Updated: 2015/03/25 19:13:05 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef LEXER_H
# define LEXER_H

# include <list>
# include <sstream>
# include <string>

# define MAX_DEGREE 1138

class Lexer
{
public:
	enum eToken
	{
		EQUAL,
		POWER,
		OPERATOR,
		VARIABLE,
		VALUE,
		NONE
	};

	typedef std::pair<eToken, std::string>	tToken;

	Lexer(void);
	~Lexer(void);

	std::list<tToken> const	&tokens(void) const;

	void					tokenize(std::string const &s);
private:
	std::list<tToken>		_tokens;

	Lexer(Lexer const &l);

	Lexer					&operator=(Lexer const &l);

	void					getEqual(void);
	void					getPower(void);
	void					getOperator(char c);
	void					getVariable(void);
	void					getValue(std::stringstream &ss, char c);
	void					checkChar(char c);
};

#endif
