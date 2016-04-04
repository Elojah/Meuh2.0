/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Expr.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 09:44:47 by leeios            #+#    #+#             */
/*   Updated: 2016/04/04 13:14:07 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPR_HPP
# define EXPR_HPP

# include <map>
# include <string>
# include <iostream>

# include "Error.hpp"
# include "Symbol.hpp"

# include <typeinfo>

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
typedef std::map<char, eValue>	state_ctr;

/*
** Interface
*/
class IExpr
{
public:
	virtual ~IExpr(void) {};
	virtual eValue		eval(const state_ctr &initStates) const = 0;
	virtual std::string	getSymbols(void) const = 0;
	virtual bool		setAll(const eValue val, state_ctr &initVals) = 0;
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
	inline virtual ~Expr(void) override
	{
		_deleteOp(m_leftOp);
		if (m_operator != eOperator::NONE)
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
	inline static std::string	_serialize(const IExpr *op) {return ( "(" + op->serialize() + ')');};
	inline static std::string	_serialize(const char op) {return (std::string(1, op));};

	inline virtual bool	setAll(const eValue val, state_ctr &initVals) override
	{
		bool	result = false;
		result = _setOp(m_leftOp, Symbol::opposite(val, m_leftNegative), initVals);
		if (m_operator != eOperator::NONE)
			result = result && _setOp(m_rightOp, Symbol::opposite(val, m_rightNegative), initVals);
		return (result);
	}
	inline static bool	_setOp(const char c, eValue val, state_ctr &initVals)
	{
		auto	initValue = initVals.find(c);
		if (initValue == initVals.end())
			return (false);
		Symbol		symInitValue(initValue->second);
		Symbol		symVal(val);
		Symbol		symNotEqual(symInitValue != symVal);
		if (initValue->second != eValue::UNDEFINED && symNotEqual.asBool())
			return (false);
		std::cout << "Set value by implication:" << c << " at " << Symbol::getName(val) << std::endl;
		initValue->second = val;
		return (true);
	};
	inline static bool	_setOp(IExpr *expr, eValue val, state_ctr &initVals) {return (expr->setAll(val, initVals));};

	inline virtual void	setLeftOperand(const T op) {m_leftOp = op;};
	inline virtual void	setRightOperand(const T op) {m_rightOp = op;};
	inline virtual void	setLeftNegative(bool neg) {m_leftNegative = neg;};
	inline virtual void	setRightNegative(bool neg) {m_rightNegative = neg;};
	inline virtual void	setOperator(const char c)
	{
		for (const auto &symbol : m_opSymbols)
		{
			if (c == symbol.second)
			{
				m_operator = symbol.first;
				break ;
			}
		}
	};

	inline virtual std::string	getSymbols(void) const override
	{
		return (_getSymbol(m_leftOp) + _getSymbol(m_rightOp));
	}
	inline static std::string	_getSymbol(const char c)
	{
		return (std::string(1, c));
	}
	inline static std::string	_getSymbol(const IExpr *op)
	{
		return (op->getSymbols());
	}


	inline virtual eValue	eval(const state_ctr &initStates) const override
	{
		if (m_operator == eOperator::NONE)
			return (_evalLeft(initStates));
		Symbol		leftVal(_evalLeft(initStates));
		Symbol		rightVal(_evalRight(initStates));
		if (m_operator == eOperator::AND)
			return (leftVal && rightVal);
		else if (m_operator == eOperator::OR)
			return (leftVal || rightVal);
		else if (m_operator == eOperator::XOR)
			return (leftVal ^ rightVal);
		return (eValue::ERROR);
	};

private:
	eOperator				m_operator;
	T						m_leftOp;
	T						m_rightOp;
	bool					m_leftNegative;
	bool					m_rightNegative;

	static const std::map<eOperator, char>	m_opSymbols;

	inline static void		_deleteOp(const IExpr *op) {delete (op);}
	inline static void		_deleteOp(const char op) {(void)op;}

	inline eValue			_evalLeft(const state_ctr &initStates) const
	{
		return (Symbol(_evalOp(m_leftOp, initStates))).getValNegative(m_leftNegative);
	};

	inline eValue			_evalRight(const state_ctr &initStates) const
	{
		return (Symbol(_evalOp(m_rightOp, initStates))).getValNegative(m_rightNegative);
	};

	// Actual template dispatching by overload
	inline static eValue	_evalOp(const char op, const state_ctr &initStates)
	{
		auto value = initStates.find(op);
		if (value != initStates.end())
			return (value->second);
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
