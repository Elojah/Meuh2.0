// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FOperand.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/27 10:47:59 by erobert           #+#    #+#             //
//   Updated: 2015/01/28 15:02:19 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "FOperand.hpp"
#include "Operand.hpp"

FOperand::FOperand(void)
{
	_function[INT8] = &FOperand::createInt8;
	_function[INT16] = &FOperand::createInt16;
	_function[INT32] = &FOperand::createInt32;
	_function[FLOAT] = &FOperand::createFloat;
	_function[DOUBLE] = &FOperand::createDouble;
}
FOperand::~FOperand(void) {}

IOperand const		*FOperand::createInt8(std::string const &value) const
{
	return (new Operand<char>(INT8, value));
}
IOperand const		*FOperand::createInt16(std::string const &value) const
{
	return (new Operand<short>(INT16, value));
}
IOperand const		*FOperand::createInt32(std::string const &value) const
{
	return (new Operand<int>(INT32, value));
}
IOperand const		*FOperand::createFloat(std::string const &value) const
{
	return (new Operand<float>(FLOAT, value));
}
IOperand const		*FOperand::createDouble(std::string const &value) const
{
	return (new Operand<double>(DOUBLE, value));
}

IOperand const		*FOperand::createOperand(eOperandType type,
											 std::string const &value) const
{
	return ((this->*_function[type])(value));
}
