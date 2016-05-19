/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 15:30:21 by leeios            #+#    #+#             */
/*   Updated: 2016/05/19 13:00:32 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Stack.h"
#include "OperandFactory.h"
#include <iostream>

Stack::eResult		Stack::doOperation(const lexOperations::sPush &param)
{
	auto elem = OperandFactory::getInstance()->createOperand(param.type, param.elem);
	m_container.push_back(elem);
	return (eResult::OK);
}
Stack::eResult		Stack::doOperation(const lexOperations::sPop &param)
{
	(void)param;
	if (m_container.empty())
		return (eResult::NOT_ENOUGH_VALUES);
	m_container.pop_back();
	return (eResult::OK);
}

Stack::eResult		Stack::doOperation(const lexOperations::sPrint &param) const
{
	(void)param;
	std::cout << m_container.back() << std::endl;
	return (eResult::OK);
}
Stack::eResult		Stack::doOperation(const lexOperations::sAssert &param) const
{
	const auto lastElem = m_container.back();
	if (param.type != lastElem->getType()
		|| param.elem.compare(lastElem->toString()) != 0)
		return (eResult::ASSERT_FALSE);
	return (eResult::OK);
}
Stack::eResult		Stack::doOperation(const lexOperations::sDump &param) const
{
	(void)param;
	for (const auto i : m_container)
		std::cout << i->toString() << std::endl;
	return (eResult::OK);
}

Stack::eResult		Stack::doOperation(const lexOperations::sAdd &param)
{
	(void)param;
	if (m_container.size() < 2)
		return (eResult::NOT_ENOUGH_VALUES);
	const auto	lhs = m_container.back();
	const auto	rhs = lhs - 1;
	const auto	result = *lhs + *rhs;
	m_container.pop_back();
	m_container.pop_back();
	m_container.push_back(result);
	return (eResult::OK);
}
Stack::eResult		Stack::doOperation(const lexOperations::sSub &param)
{
	(void)param;
	if (m_container.size() < 2)
		return (eResult::NOT_ENOUGH_VALUES);
	const auto	lhs = m_container.back();
	const auto	rhs = lhs - 1;
	const auto	result = *lhs - *rhs;
	m_container.pop_back();
	m_container.pop_back();
	m_container.push_back(result);
	return (eResult::OK);
}
Stack::eResult		Stack::doOperation(const lexOperations::sMul &param)
{
	(void)param;
	if (m_container.size() < 2)
		return (eResult::NOT_ENOUGH_VALUES);
	const auto	lhs = m_container.back();
	const auto	rhs = lhs - 1;
	const auto	result = *lhs * *rhs;
	m_container.pop_back();
	m_container.pop_back();
	m_container.push_back(result);
	return (eResult::OK);
}
Stack::eResult		Stack::doOperation(const lexOperations::sDiv &param)
{
	(void)param;
	if (m_container.size() < 2)
		return (eResult::NOT_ENOUGH_VALUES);
	const auto	lhs = m_container.back();
	const auto	rhs = lhs - 1;
	if (rhs->toString().compare("0") == 0
		|| rhs->toString().compare("0.") == 0
		|| rhs->toString().compare("0.0") == 0)
		return (eResult::DIV_BY_ZERO);
	const auto	result = *lhs / *rhs;
	m_container.pop_back();
	m_container.pop_back();
	m_container.push_back(result);
	return (eResult::OK);
}
Stack::eResult		Stack::doOperation(const lexOperations::sMod &param)
{
	(void)param;
	if (m_container.size() < 2)
		return (eResult::NOT_ENOUGH_VALUES);
	const auto	lhs = m_container.back();
	const auto	rhs = lhs - 1;
	if (rhs->toString().compare("0") == 0
		|| rhs->toString().compare("0.") == 0
		|| rhs->toString().compare("0.0") == 0)
		return (eResult::DIV_BY_ZERO);
	const auto	result = *lhs % *rhs;
	m_container.pop_back();
	m_container.pop_back();
	m_container.push_back(result);
	return (eResult::OK);
}
