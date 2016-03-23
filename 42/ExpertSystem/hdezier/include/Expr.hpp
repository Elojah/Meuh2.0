/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Expr.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 09:44:47 by leeios            #+#    #+#             */
/*   Updated: 2016/03/16 11:09:31 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPR_HPP
# define EXPR_HPP

#include "IExpr.hpp"

#include <string>

#include "specialization.h"

# define XOR(a, b) (!(a) != !(b))

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
		m_rightNegative(false) {};
	virtual ~Expr(void);

	virtual void	setLeftOperand(const Left *op) {m_leftOp = op;};
	virtual void	setRightOperand(const Right &op) {m_rightOp = op;};
	virtual void	setLeftNegative(bool neg) {m_leftNegative = neg;};
	virtual void	setRightNegative(bool neg) {m_rightNegative = neg;};
	virtual void	setOperator(const std::string &op)
	{
		if (op.empty())
			return ;
		switch (op[0])
		{
			case ('+') : m_operator = eOperator::AND; break;
			case ('|') : m_operator = eOperator::OR; break;
			case ('^') : m_operator = eOperator::XOR; break;
		}
	};

	virtual bool	eval(void) const override
	{
		switch (m_operator)
		{
			case (eOperator::AND) :
				return (_evalLeft() && _evalRight());
			case (eOperator::OR) :
				return (_evalLeft() || _evalRight());
			case (eOperator::XOR) :
				return (XOR(_evalLeft(), _evalRight()));
			default :
				return (false);
		};
	};

private:
	Left			*m_leftOp;
	bool			m_leftNegative;
	Right			*m_rightOp;
	bool			m_rightNegative;
	eOperator		m_operator;

	bool			_evalLeft(void) const {return (XOR(m_leftOp->eval(), m_leftNegative));};
	bool			_evalRight(void) const {return (XOR(m_rightOp->eval(), m_rightNegative));};
};

#endif
