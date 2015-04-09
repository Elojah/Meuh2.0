// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   OfficeBlock.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/12 17:50:32 by erobert           #+#    #+#             //
//   Updated: 2015/01/12 18:20:59 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock(void):
	_sB(NULL),
	_eB(NULL),
	_i(NULL)
{}
OfficeBlock::OfficeBlock(Bureaucrat *sB, Bureaucrat *eB, Intern *i):
	_sB(sB),
	_eB(eB),
	_i(i)
{
}
OfficeBlock::~OfficeBlock(void) {}

void	OfficeBlock::setSigner(Bureaucrat *b)
{
	_sB = b;
}
void	OfficeBlock::setExecutor(Bureaucrat *b)
{
	_eB = b;
}
void	OfficeBlock::setIntern(Intern *i)
{
	_i = i;
}

void	OfficeBlock::doBureaucracy(std::string const &fN, std::string const &tN)
{
	Form	*f;

	if (!_i || !_sB || !_eB)
	{
		std::cout << "Office problem: not enough staff" << std::endl;
		return ;
	}
	f = _i->makeForm(fN, tN);
	if (f == NULL)
		return ;
	try
	{
		f->beSigned(*_sB);
		std::cout << *f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Office problem: can't be signed" << std::endl;
	}
	try
	{
		_eB->executeForm(*f);
	}
	catch (std::exception &e)
	{
		std::cout << "Office problem: can't be executed" << std::endl;
	}
	delete f;
}
