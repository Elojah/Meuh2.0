/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 16:50:10 by leeios            #+#    #+#             */
/*   Updated: 2016/05/19 16:54:21 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.h"
#include "IOperand.h"
#include "Stack.h"

#include <iostream>
#include <map>

Lexer::eResult		Lexer::read_line(const std::string &line, Stack &stack)
{
	auto	type = _analyzeType(line);
	if (type == eToken::PUSH)
	{
		lexOperations::sPush	typePush;
		if (_setElem(typePush, line) == false) return (eResult::ERR);
		stack.doOperation(typePush);
	}
	else if (type == eToken::POP)
	{
		lexOperations::sPop		typePop;
		stack.doOperation(typePop);
	}
	else if (type == eToken::PRINT)
	{
		lexOperations::sPrint	typePrint;
		stack.doOperation(typePrint);
	}
	else if (type == eToken::DUMP)
	{
		lexOperations::sDump	typeDump;
		stack.doOperation(typeDump);
	}
	else if (type == eToken::ASSERT)
	{
		lexOperations::sAssert	typeAssert;
		if (_setElem(typeAssert, line) == false) return (eResult::ERR);
		stack.doOperation(typeAssert);
	}
	else if (type == eToken::ADD)
	{
		lexOperations::sAdd		typeAdd;
		stack.doOperation(typeAdd);
	}
	else if (type == eToken::SUB)
	{
		lexOperations::sSub		typeSub;
		stack.doOperation(typeSub);
	}
	else if (type == eToken::MUL)
	{
		lexOperations::sMul		typeMul;
		stack.doOperation(typeMul);
	}
	else if (type == eToken::DIV)
	{
		lexOperations::sDiv		typeDiv;
		stack.doOperation(typeDiv);
	}
	else if (type == eToken::MOD)
	{
		lexOperations::sMod		typeMod;
		stack.doOperation(typeMod);
	}
	else if (type == eToken::QUIT)
		return (eResult::QUIT);
	else
		return (eResult::ERR);
	return (eResult::OK);
}

eToken	Lexer::_analyzeType(const std::string &line)
{
	static const std::map<std::string, eToken>		analyzeMap =
	{
		{"push", eToken::PUSH},
		{"print", eToken::PRINT},
		{"assert", eToken::ASSERT},
		{"pop", eToken::POP},
		{"dump", eToken::DUMP},
		{"add", eToken::ADD},
		{"sub", eToken::SUB},
		{"mul", eToken::MUL},
		{"div", eToken::DIV},
		{"mod", eToken::MOD},
		{"quit", eToken::QUIT}
	};
	for (const auto compareElem : analyzeMap)
	{
		const int		sizeTocompare(compareElem.first.size());
		if (compareElem.first.compare(0, sizeTocompare
			, line.c_str(), sizeTocompare) == 0)
			return (compareElem.second);
	}
	return (eToken::ERR);
}

bool	Lexer::_setElem(lexOperations::sElem &elem, const std::string &line)
{
	static const std::map<std::string, IOperand::eOperandType>		analyzeMap =
	{
		{"int8", IOperand::eOperandType::Int8},
		{"int16", IOperand::eOperandType::Int16},
		{"int32", IOperand::eOperandType::Int32},
		{"float", IOperand::eOperandType::Float},
		{"double", IOperand::eOperandType::Double}
	};

	const auto	firstDelim = line.find_first_of(' ');
	if (firstDelim == std::string::npos
		|| firstDelim == line.size() - 1)
		return (false);
	const auto	type = line.substr(firstDelim + 1);
	for (const auto compareElem : analyzeMap)
	{
		const int		sizeTocompare(compareElem.first.size());
		if (compareElem.first.compare(0, sizeTocompare
			, type.c_str(), sizeTocompare) == 0)
		{
			elem.type = compareElem.second;
			const auto	openParenthesis = type.find_first_of('(');
			const auto	closeParenthesis = type.find_first_of(')');
			if (openParenthesis == std::string::npos
				|| openParenthesis == line.size() - 1
				|| closeParenthesis == std::string::npos
				|| closeParenthesis == 0
				|| closeParenthesis < openParenthesis)
				return (false);
			elem.elem = type.substr(openParenthesis + 1, closeParenthesis - 1);
			return (true);
		}
	}
	return (false);
}
