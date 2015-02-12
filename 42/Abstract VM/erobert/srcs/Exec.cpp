// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Exec.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/27 10:27:42 by erobert           #+#    #+#             //
//   Updated: 2015/01/28 18:47:31 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Exec.hpp"
#include "Operand.hpp"

Exec::Exec(void) {}
Exec::~Exec(void) {}

void				Exec::push(eOperandType type, std::string const &value)
{
	_cmd.push_back(_fO.createOperand(type, value));
}
void				Exec::pop(void)
{
	if (_cmd.size() < 1)
		throw BadStack();
	else
		_cmd.pop_back();
}
void				Exec::dump(void)
{
	std::list<IOperand const *>::iterator	ib(_cmd.begin());
	std::list<IOperand const *>::iterator	it(_cmd.end());

	while (it-- != ib)
		std::cout << (*it)->toString() << std::endl;
}
void				Exec::assert(eOperandType type, std::string const &value)
{
	if (_cmd.size() < 1)
		throw BadStack();
	if (_cmd.back()->getType() == type && _cmd.back()->toString() == value)
		return ;
	throw BadAssert();
}
void				Exec::doOp(eInstruction instr)
{
	IOperand const	*a;
	IOperand const	*b;

	if (_cmd.size() < 2)
		throw BadStack();
	a = _cmd.back();
	pop();
	b = _cmd.back();
	pop();
	if (instr == ADD)
		_cmd.push_back(*a + *b);
	else if (instr == SUB)
		_cmd.push_back(*a - *b);
	else if (instr == MUL)
		_cmd.push_back(*a * *b);
	else if (instr == DIV)
		_cmd.push_back(*a / *b);
	else
		_cmd.push_back(*a % *b);
}
void				Exec::print(void)
{
	if (_cmd.size() < 1)
		throw BadStack();
	else if (_cmd.back()->getType() != INT8)
		throw BadPrint();
	std::cout << static_cast<char>(std::atoi(_cmd.back()->toString().c_str()))
			  << std::endl;
}
void				Exec::exit(void)
{
	std::list<IOperand const *>::iterator	it(_cmd.begin());
	std::list<IOperand const *>::iterator	ie(_cmd.end());

	while (it != ie)
	{
		delete *it;
		it++;
	}
}

void				Exec::execCommand(std::list<sCommand> cmd)
{
	std::list<sCommand>::iterator	ib(cmd.begin());
	std::list<sCommand>::iterator	it(cmd.end());
	
	while (it-- != ib)
	{
		if (it->instr == POP)
			pop();
		else if (it->instr == DUMP)
			dump();
		else if (it->instr == PRINT)
			print();
		else if (it->instr == EXIT)
			exit();
		else if (it->instr == PUSH)
			push(it->op, it->val);
		else if (it->instr == ASSERT)
			assert(it->op, it->val);
		else
			doOp(it->instr);
	}
}

Exec::BadStack::BadStack(void) {}
Exec::BadStack::~BadStack(void) throw() {}

char const			*Exec::BadStack::what(void) const throw()
{
	return ("Bad stack.");
}
Exec::BadAssert::BadAssert(void) {}
Exec::BadAssert::~BadAssert(void) throw() {}

char const			*Exec::BadAssert::what(void) const throw()
{
	return ("Wrong assert.");
}
Exec::BadPrint::BadPrint(void) {}
Exec::BadPrint::~BadPrint(void) throw() {}

char const			*Exec::BadPrint::what(void) const throw()
{
	return ("Wrong print.");
}
