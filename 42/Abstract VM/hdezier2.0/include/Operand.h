/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 17:18:40 by leeios            #+#    #+#             */
/*   Updated: 2016/05/17 19:14:39 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_H
# define OPERAND_H

# include "IOperand.h"
# include "OperandFactory.h"

template<typename T>
class		Operand : public IOperand
{
public:
	Operand(void) = default;
	virtual ~Operand(void) = default;

	inline bool					setValue(const std::string &value)
	{
		auto	type = getType();
		switch (type)
		{
			case (IOperand::eOperandType::Int8) :
			case (IOperand::eOperandType::Int16) :
			case (IOperand::eOperandType::Int32) :
				m_value = std::atoi(value.c_str());
				break ;
			case (IOperand::eOperandType::Float) :
				m_value = std::atof(value.c_str());
				break ;
			case (IOperand::eOperandType::Double) :
				m_value = std::atol(value.c_str());
				break ;
		}
		return (true);
	};

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

	virtual IOperand const		*operator+(IOperand const &rhs) const override
	{
		if (getPrecision() > rhs.IOperand::getPrecision())
			return (m_factory.createOperand(getType(), ))
	}
	virtual IOperand const		*operator-(IOperand const &rhs) const override;
	virtual IOperand const		*operator*(IOperand const &rhs) const override;
	virtual IOperand const		*operator/(IOperand const &rhs) const override;
	virtual IOperand const		*operator%(IOperand const &rhs) const override;

	virtual std::string const	&toString(void) const override
	{
		std::to_string(m_value);
	}

private:
	T				m_value;
	OperandFactory	m_factory;
};

#endif
