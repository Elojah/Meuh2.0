/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Expr.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 09:44:47 by leeios            #+#    #+#             */
/*   Updated: 2016/03/20 18:56:20 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPR_HPP
# define EXPR_HPP

# include <map>
# include <string>
# include <iostream>

# include "Error.hpp"

# include <typeinfo>

// DANGER !!! EVALUATE TWICE
# define XOR_VAL(a, b) (((a) == eValue::TRUE && (b) == eValue::FALSE) || ((a) == eValue::FALSE && (b) == eValue::TRUE))

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
	virtual eValue	eval(const state_ctr &initStates) const = 0;
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
	inline Expr(void) :
		m_operator(eOperator::NONE),
		m_leftNegative(false),
		m_rightNegative(false)
	{};
	// TODO : LEAKS !!! leftOp & rightOp
	inline virtual ~Expr(void)
	{};

	inline virtual void	setLeftOperand(const Left op) {m_leftOp = op;};
	inline virtual void	setRightOperand(const Right op) {m_rightOp = op;};
	inline virtual void	setLeftNegative(bool neg) {m_leftNegative = neg;};
	inline virtual void	setRightNegative(bool neg) {m_rightNegative = neg;};
	inline virtual void	setOperator(const char c)
	{
		switch (c)
		{
			case ('+') : m_operator = eOperator::AND; break;
			case ('|') : m_operator = eOperator::OR; break;
			case ('^') : m_operator = eOperator::XOR; break;
		}
	};

	inline virtual eValue	eval(const state_ctr &initStates) const override
	{
		std::cerr
		<< std::string("Eval: Left_") + typeid(m_leftOp).name()
		+ std::string("_Right_") + typeid(m_rightOp).name()
		 << std::endl;
		if (m_operator == eOperator::NONE)
			return (_evalLeft(initStates));
		eValue		leftVal = _evalLeft(initStates);
		eValue		rightVal = _evalRight(initStates);
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

private:
	eOperator					m_operator;
	Left						m_leftOp;
	Right						m_rightOp;
	bool						m_leftNegative;
	bool						m_rightNegative;

	inline eValue			_evalLeft(const state_ctr &initStates) const
	{
		std::cerr << "____eval Left" << std::endl;
		bool val = (_evalOp(m_leftOp, initStates) == eValue::TRUE);
		return (XOR(val, m_leftNegative) ?
			eValue::TRUE :
			eValue::FALSE);
	};

	inline eValue			_evalRight(const state_ctr &initStates) const
	{
		std::cerr << "____eval Right" << std::endl;
		bool val = (_evalOp(m_rightOp, initStates) == eValue::TRUE);
		return (XOR(val, m_rightNegative) ?
			eValue::TRUE :
			eValue::FALSE);
	};

	// Actual template dispatching by overload
	inline static eValue	_evalOp(const char op, const state_ctr &initStates)
	{
		std::cerr << "____eval as char" << std::endl;
		auto value = initStates.find(op);
		if (value != initStates.end())
		{
			if (value->second == eValue::UNDEFINED)
				;// TODO : Calculate value by inference
			return (value->second);
		}
		else
			return (eValue::ERROR);
	};

	inline static eValue	_evalOp(const IExpr *op, const state_ctr &initStates)
	{
		std::cerr << "____eval as IExpr*" << std::endl;
		return (op->eval(initStates));
	};

};

#endif
