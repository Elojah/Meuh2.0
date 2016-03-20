/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Expr.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 09:44:47 by leeios            #+#    #+#             */
/*   Updated: 2016/03/20 13:05:39 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPR_HPP
# define EXPR_HPP

# include <map>
# include <string>
# include <iostream>

# include "Error.hpp"

// DANGER !!! EVALUATE TWICE
# define XOR_VAL(a, b) (((a) == eValue::TRUE && (b) == eValue::FALSE)\
					|| ((a) == eValue::FALSE && (b) == eValue::TRUE))

#define XOR(a, b) (!(a) != !(b))

enum class	eValue
{
	UNDEFINED = 0,
	TRUE,
	FALSE,
	ERROR
};
typedef std::map<char, eValue>	state_ctr;

class IExpr
{
public:
	virtual ~IExpr(void) {};
	virtual eValue	eval(void) const = 0;
};

template<typename Left, typename Right>
class	Expr : public IExpr
{

	enum class	eOperator
	{
		NONE = 0,
		AND,
		OR,
		XOR
	};

public :
	Expr(void) :
		m_operator(eOperator::NONE),
		m_leftNegative(false),
		m_rightNegative(false)
	{};
	// TODO : LEAKS !!! leftOp & rightOp
	virtual ~Expr(void)
	{};

	virtual void	setLeftOperand(const Left op) {m_leftOp = op;};
	virtual void	setRightOperand(const Right op) {m_rightOp = op;};
	virtual void	setLeftNegative(bool neg) {m_leftNegative = neg;};
	virtual void	setRightNegative(bool neg) {m_rightNegative = neg;};
	virtual void	setOperator(const char c)
	{
		switch (c)
		{
			case ('+') : m_operator = eOperator::AND; break;
			case ('|') : m_operator = eOperator::OR; break;
			case ('^') : m_operator = eOperator::XOR; break;
		}
	};

	virtual eValue	eval(void) const override
	{
		if (m_operator == eOperator::NONE)
			return (_evalLeft());
		eValue		leftVal = _evalLeft();
		eValue		rightVal = _evalRight();
		if (m_operator == eOperator::AND)
		{
			return ((leftVal == eValue::TRUE && rightVal == eValue::TRUE) ?
				eValue::TRUE :
				eValue::FALSE);
		}
		else if (m_operator == eOperator::OR)
		{
			return ((leftVal == eValue::TRUE || rightVal == eValue::TRUE) ?
				eValue::TRUE :
				eValue::FALSE);
		}
		else if (m_operator == eOperator::XOR)
		{
			return (XOR_VAL(leftVal, rightVal) ?
				eValue::TRUE :
				eValue::FALSE);
		}
		return (eValue::ERROR);
	};

	void	setInitStates(const state_ctr *initStates)
	{
		m_initialStates = initStates;
	}

private:
	eOperator					m_operator;
	Left						m_leftOp;
	Right						m_rightOp;
	bool						m_leftNegative;
	bool						m_rightNegative;
	static const state_ctr		*m_initialStates;

	// POSSIBLE ERROR: Call evalOp<Left/Right>() instead of evalOp()
	eValue			_evalLeft(void) const
	{
		bool val = (_evalOp(m_leftOp) == eValue::TRUE);
		return (XOR(val, m_leftNegative) ?
			eValue::TRUE :
			eValue::FALSE);
	};
	eValue			_evalRight(void) const
	{
		bool val = (_evalOp(m_rightOp) == eValue::TRUE);
		return (XOR(val, m_rightNegative) ?
			eValue::TRUE :
			eValue::FALSE);
	};

	// Actual template dispatching by overload
	template<typename T>
	static eValue	_evalOp(T op)
	{
		(void)op;
		err::raise_error(eErr::FATAL, "Error: Can't eval this type, unrecognized value");
		return (eValue::ERROR);
	};
	static eValue	_evalOp(const char op)
	{
		auto value = m_initialStates->find(op);
		if (value != m_initialStates->end())
		{
			if (value->second == eValue::UNDEFINED)
				;// TODO : Calculate value by inference
			return (value->second);
		}
		else
			return (eValue::ERROR);
	};
	static eValue	_evalOp(const IExpr *op)
	{
		return (op->eval());
	};
};

#endif
