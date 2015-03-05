// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Parser.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/05 19:20:26 by erobert           #+#    #+#             //
//   Updated: 2015/03/05 21:00:09 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PARSER_H
# define PARSER_H

# include <iostream>
# include <list>
# include <sstream>
# include <vector>
# include "Lexer.hpp"

class Parser
{
public:
	typedef Lexer::tToken				tToken;
	typedef std::list<tToken>::iterator	tTI;

	Parser(void);
	~Parser(void);

	unsigned int				getSize(void) const;

	std::vector<int>			&parse(std::list<tToken> &tokens);
private:
	std::vector<int>			_vector;
	unsigned int				_size;

	Parser(Parser const &p);

	Parser						&operator=(Parser const &p);

	int							checkSize(tToken &token);
	tTI							checkValues(tTI it, tTI ie);
};

#endif
