// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Parser.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/24 04:11:16 by erobert           #+#    #+#             //
//   Updated: 2015/01/27 15:09:14 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PARSER_HPP
# define PARSER_HPP

# include <iostream>
# include <list>
# include <sstream>
# include <string>
# include "avm.h"

class Parser
{
private:
	std::list<sCommand>	_cmd;
	std::string			_instruction[11];
	std::string			_type[5];
	bool				_exit;

	Parser(Parser const &p);

	Parser				&operator=(Parser const &p);
public:
	Parser(void);
	~Parser(void);

	std::list<sCommand>	getCmd(void) const;
	bool				gotExit(void) const;

	void				pushCommand(eOperandType op, eInstruction instr, 
									std::string val);
	int					getInstruction(std::string const &line);
	int					getType(std::string const &line);
	void				parseInt(std::string const &value);
	void				parseFloat(std::string const &value);
	void				parseValue(std::string const &line, eInstruction instr);
	void				parseLine(std::string const &line);

	class BadInstruction: public std::exception
	{
	private:
		BadInstruction		&operator=(BadInstruction const &bI);
	public:
		BadInstruction(void);
		BadInstruction(BadInstruction const &bI);
		virtual ~BadInstruction(void) throw();

		virtual char const	*what(void) const throw();
	};
	class BadValue: public std::exception
	{
	private:
		BadValue		    &operator=(BadValue const &bV);
	public:
		BadValue(void);
		BadValue(BadValue const &bV);
		virtual ~BadValue(void) throw();

		virtual char const	*what(void) const throw();
	};
	class NoExit: public std::exception
	{
	private:
		NoExit			    &operator=(NoExit const &nE);
	public:
		NoExit(void);
		NoExit(NoExit const &nE);
		virtual ~NoExit(void) throw();

		virtual char const	*what(void) const throw();
	};
};

#endif
