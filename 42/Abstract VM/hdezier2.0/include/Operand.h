/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 17:18:40 by leeios            #+#    #+#             */
/*   Updated: 2016/05/19 16:48:27 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_H
# define OPERAND_H

# include "IOperand.h"
# include "OperandFactory.h"
# include "type_helper.h"

template<typename T>
class		Operand : public IOperand
{
public:
	Operand(void) = default;
	Operand(const std::string &value);
	virtual ~Operand(void) = default;

	inline virtual int			getPrecision(void) const override
	{
		return (sizeof(m_value));
	};

private:
	inline static eOperandType	_getType(const int8_t &value)
	{
		(void)value;
		return (IOperand::eOperandType::Int8);
	}
	inline static eOperandType	_getType(const int16_t &value)
	{
		(void)value;
		return (IOperand::eOperandType::Int16);
	}
	inline static eOperandType	_getType(const int32_t &value)
	{
		(void)value;
		return (IOperand::eOperandType::Int32);
	}
	inline static eOperandType	_getType(const float &value)
	{
		(void)value;
		return (IOperand::eOperandType::Float);
	}
	inline static eOperandType	_getType(const double &value)
	{
		(void)value;
		return (IOperand::eOperandType::Double);
	}
public:
	inline virtual eOperandType	getType(void) const override
	{
		return (_getType(m_value));
	};

	inline virtual IOperand const		*operator+(IOperand const &rhs) const override
	{
		return (_doOperation<helper::sAdd>(rhs));
	};
	inline virtual IOperand const		*operator-(IOperand const &rhs) const override
	{
		return (_doOperation<helper::sSub>(rhs));
	};
	inline virtual IOperand const		*operator*(IOperand const &rhs) const override
	{
		return (_doOperation<helper::sMul>(rhs));
	};
	inline virtual IOperand const		*operator/(IOperand const &rhs) const override
	{
		return (_doOperation<helper::sDiv>(rhs));
	};
	inline virtual IOperand const		*operator%(IOperand const &rhs) const override
	{
		return (_doOperation<helper::sMod>(rhs));
	};

	virtual std::string const	&toString(void) const override
	{
		return (m_strValue);
	}

private:
	const T							m_value;
	const std::string				m_strValue;

	template<typename OperationType>
	IOperand const		*_doOperation(IOperand const &rhs) const;
};

#endif
