/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 17:38:13 by leeios            #+#    #+#             */
/*   Updated: 2016/05/19 14:12:56 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Operand.h"
#include "OperandFactory.h"

OperandFactory		*OperandFactory::m_instance = nullptr;

OperandFactory		*OperandFactory::getInstance(void)
{
	if (m_instance == nullptr)
		m_instance = new OperandFactory;
	return (m_instance);
}


IOperand const		*OperandFactory::createOperand(IOperand::eOperandType type, std::string const & value) const
{
	static const creator		switchRedirection[(int)IOperand::eOperandType::E_TYPE] =
	{
		&OperandFactory::createInt8,
		&OperandFactory::createInt16,
		&OperandFactory::createInt32,
		&OperandFactory::createFloat,
		&OperandFactory::createDouble
	};
	return ((this->*(switchRedirection[(int)type]))(value));
}
IOperand const		*OperandFactory::createInt8(std::string const & value) const
{
	auto result = new Operand<int8_t>;
	if (result->setValue(value) == false)
		return (nullptr);
	return (result);
}
IOperand const		*OperandFactory::createInt16(std::string const & value) const
{
	auto result = new Operand<int16_t>;
	if (result->setValue(value) == false)
		return (nullptr);
	return (result);
}
IOperand const		*OperandFactory::createInt32(std::string const & value) const
{
	auto result = new Operand<int32_t>;
	if (result->setValue(value) == false)
		return (nullptr);
	return (result);
}
IOperand const		*OperandFactory::createFloat(std::string const & value) const
{
	auto result = new Operand<float>;
	if (result->setValue(value) == false)
		return (nullptr);
	return (result);
}
IOperand const		*OperandFactory::createDouble(std::string const & value) const
{
	auto result = new Operand<double>;
	if (result->setValue(value) == false)
		return (nullptr);
	return (result);
}
