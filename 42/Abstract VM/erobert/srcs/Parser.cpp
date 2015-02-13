// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Parser.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/24 04:25:09 by erobert           #+#    #+#             //
//   Updated: 2015/01/28 18:47:13 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Parser.hpp"

Parser::Parser(void):
	_exit(false)
{
	_instruction[POP] = "pop";
	_instruction[DUMP] = "dump";
	_instruction[ADD] = "add";
	_instruction[SUB] = "sub";
	_instruction[MUL] = "mul";
	_instruction[DIV] = "div";
	_instruction[MOD] = "mod";
	_instruction[PRINT] = "print";
	_instruction[EXIT] = "exit";
	_instruction[PUSH] = "push";
	_instruction[ASSERT] = "assert";
	_type[INT8] = " int8(";
	_type[INT16] = " int16(";
	_type[INT32] = " int32(";
	_type[FLOAT] = " float(";
	_type[DOUBLE] = " double(";
}
Parser::~Parser(void) {}

std::list<sCommand>		Parser::getCmd(void) const
{
	return (_cmd);
}
bool					Parser::gotExit(void) const
{
	return (_exit);
}

void					Parser::pushCommand(eOperandType op,
											eInstruction instr,
											std::string val)
{
	sCommand			cmd;

	cmd.op = op;
	cmd.instr = instr;
	cmd.val = val.substr(0, val.size() - 1);
	_cmd.push_front(cmd);
}
int						Parser::getInstruction(std::string const &line)
{
	int					i(-1);

	while (++i < 9)
	{
		if (line.compare(_instruction[i]) == 0)
		{
			if (i == EXIT)
				_exit = true;
			return (i);
		}
	}
	throw BadInstruction();
	return (-1);
}
int						Parser::getType(std::string const &line)
{
	int					i(-1);

	while (++i < 5)
	{
		if (line.compare(0, _type[i].size(), _type[i]) == 0)
			return (i);
	}
	throw BadInstruction();
	return (-1);
}
void					Parser::parseInt(std::string const &value)
{
	size_t				i(0);

	if (value[i] == '-' || value[i] == '+')
		i++;
	while (isdigit(value[i]))
		i++;
	if (value[i] == ')' && !value[i + 1])
		return ;
	throw BadValue();
}
void					Parser::parseFloat(std::string const &value)
{
	size_t				i(0);

	if (value[i] == '-' || value[i] == '+')
		i++;
	while (isdigit(value[i]))
		i++;
	if (value[i] == '.')
	{
		while (isdigit(value[++i]))
			;
	}
	if (value[i] == ')' && !value[i + 1])
		return ;
	throw BadValue();
}
void					Parser::parseValue(std::string const &line,
										   eInstruction instr)
{
	char const			*str(line.c_str());
	size_t				i(_instruction[instr].size());
	int					type;

	if (*(str + i) != ' ')
		throw BadInstruction();
	type = getType(str + i);
	if (type < 3)
		parseInt(str + i + _type[type].size());
	else
		parseFloat(str + i + _type[type].size());
	pushCommand(static_cast<eOperandType>(type),
				static_cast<eInstruction>(instr),
				str + i + _type[type].size());
}
void					Parser::parseLine(std::string const &line)
{
	std::stringstream	stream(line);
	std::string			str;
	sCommand			cmd;
	int					instr;

	if (line.c_str()[0] == ';' || line.c_str()[0] == '\0')
		return ;
	stream >> str;
	if (str.compare(_instruction[PUSH]) == 0)
		parseValue(line, PUSH);
	else if (str.compare(_instruction[ASSERT]) == 0)
		parseValue(line, ASSERT);
	else
	{
		instr = getInstruction(line);
		pushCommand(NONE, static_cast<eInstruction>(instr), "");
	}
}

Parser::BadInstruction::BadInstruction(void) {}
Parser::BadInstruction::~BadInstruction(void) throw() {}

char const					*Parser::BadInstruction::what(void) const throw()
{
	return ("Bad instruction.");
}

Parser::BadValue::BadValue(void) {}
Parser::BadValue::~BadValue(void) throw() {}

char const					*Parser::BadValue::what(void) const throw()
{
	return ("Bad value.");
}

Parser::NoExit::NoExit(void) {}
Parser::NoExit::~NoExit(void) throw() {}

char const					*Parser::NoExit::what(void) const throw()
{
	return ("No exit instruction.");
}
