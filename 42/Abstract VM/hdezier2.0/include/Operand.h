/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 17:18:40 by leeios            #+#    #+#             */
/*   Updated: 2016/05/19 14:21:14 by hdezier          ###   ########.fr       */
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
	virtual ~Operand(void) = default;

	inline bool					setValue(const std::string &value)
	{
		m_value = helper::_convertTo<T>(value);
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
		std::to_string(m_value);
	}

private:
	T							m_value;

	template<typename OperationType>
	IOperand const		*_doOperation(IOperand const &rhs) const
	{
		IOperand::eOperandType	resultType;
		if (getPrecision() > rhs.getPrecision())
			resultType = getType();
		else
			resultType = rhs.getType();
		switch (resultType)
		{
			case (IOperand::eOperandType::Int8) :
				return
				(
					OperandFactory::getInstance()->createOperand(resultType, std::to_string(OperationType::operate<int8_t>(toString(), rhs.toString())))
				);
			case (IOperand::eOperandType::Int16) :
				return
				(
					OperandFactory::getInstance()->createOperand(resultType, std::to_string(OperationType::operate(toString(), rhs.toString())))
				);
			case (IOperand::eOperandType::Int32) :
				return
				(
					OperandFactory::getInstance()->createOperand(resultType, std::to_string(OperationType::operate(toString(), rhs.toString())))
				);
			case (IOperand::eOperandType::Float) :
				return
				(
					OperandFactory::getInstance()->createOperand(resultType, std::to_string(OperationType::operate(toString(), rhs.toString())))
				);
			case (IOperand::eOperandType::Double) :
				return
				(
					OperandFactory::getInstance()->createOperand(resultType, std::to_string(OperationType::operate(toString(), rhs.toString())))
				);
			default : break ;
		};
	}

};

#endif
