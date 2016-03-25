/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Expr.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 09:44:47 by leeios            #+#    #+#             */
/*   Updated: 2016/03/25 15:09:09 by leeios           ###   ########.fr       */
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
# define XOR(a, b) (!(a) != !(b))

/*
** Type definitions
*/
enum class	eOperator
{
	NONE = 0,
	AND,
	OR,
	XOR
};
enum class	eValue
{
	UNDEFINED = 0,
	TRUE,
	FALSE,
	ERROR
};
typedef std::map<char, eValue>	state_ctr;

/*
** Interface
*/
class IExpr
{
public:
	virtual ~IExpr(void) {};
	virtual eValue		eval(const state_ctr &initStates) const = 0;
	virtual std::string	serialize(void) const = 0;
};

/*
** Implementation
*/
template<typename T>
class	Expr : public IExpr
{
public :
	inline Expr(void) :
		m_operator(eOperator::NONE),
		m_leftNegative(false),
		m_rightNegative(false)
	{};
	// TODO : LEAKS !!! leftOp & rightOp
	inline virtual ~Expr(void) override
	{
		_deleteOp(m_leftOp);
		_deleteOp(m_rightOp);
	};
	inline virtual std::string	serialize(void) const override
	{
		std::string		result;
		if (m_leftNegative)
			result += '!';
		result += _serialize(m_leftOp);
		if (m_operator == eOperator::NONE)
			return (result);
		result += m_opSymbols.at(m_operator);
		if (m_rightNegative)
			result += '!';
		result += _serialize(m_rightOp);
		return (result);
	};
	inline virtual std::string	_serialize(const IExpr *op) const {return ( "(" + op->serialize() + ')');};
	inline virtual std::string	_serialize(const char op) const {return (std::string(1, op));};

	inline virtual void	setLeftOperand(const T op) {m_leftOp = op;};
	inline virtual void	setRightOperand(const T op) {m_rightOp = op;};
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
	eOperator				m_operator;
	T						m_leftOp;
	T						m_rightOp;
	bool					m_leftNegative;
	bool					m_rightNegative;

	static const std::map<eOperator, char>	m_opSymbols;

	inline virtual void		_deleteOp(const IExpr *op) {delete (op);}
	inline virtual void		_deleteOp(const char op) {(void)op;}

	inline eValue			_evalLeft(const state_ctr &initStates) const
	{
		bool val = (_evalOp(m_leftOp, initStates) == eValue::TRUE);
		return (XOR(val, m_leftNegative) ?
			eValue::TRUE :
			eValue::FALSE);
	};

	inline eValue			_evalRight(const state_ctr &initStates) const
	{
		bool val = (_evalOp(m_rightOp, initStates) == eValue::TRUE);
		return (XOR(val, m_rightNegative) ?
			eValue::TRUE :
			eValue::FALSE);
	};

	// Actual template dispatching by overload
	inline static eValue	_evalOp(const char op, const state_ctr &initStates)
	{
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
		return (op->eval(initStates));
	};

};

template<typename T>
const std::map<eOperator, char>		Expr<T>::m_opSymbols =
{
	{eOperator::AND, '+'},
	{eOperator::OR, '|'},
	{eOperator::XOR, '^'}
};

#endif
