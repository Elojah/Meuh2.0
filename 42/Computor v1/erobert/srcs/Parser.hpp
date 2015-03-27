// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Parser.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/05 19:20:26 by erobert           #+#    #+#             //
//   Updated: 2015/03/25 19:12:36 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PARSER_H
# define PARSER_H

# include <algorithm>
# include <iostream>
# include <list>
# include <sstream>
# include <vector>
# include "Lexer.hpp"

class Parser
{
public:
	struct sItem
	{
		char					operand;
		float					value;
	};
	typedef Lexer::tToken						tToken;
	typedef std::list<tToken>::const_iterator	tTI;

	Parser(void);
	~Parser(void);

	bool						good(void) const;
	std::vector<float> const	&vector(void) const;

	void						parse(std::list<tToken> const &tokens);
private:
	bool						_good;
	std::vector<float>			_vector;

	Parser(Parser const &p);

	Parser						&operator=(Parser const &p);

	void						setError(void);
	void						checkValue(std::string const &value);
	float						getValue(tTI &it);
	size_t						getDegree(tTI &it, tTI &ie);
	void						checkItem(tTI &it, tTI &ie,
										  bool right, bool first);
};

#endif
