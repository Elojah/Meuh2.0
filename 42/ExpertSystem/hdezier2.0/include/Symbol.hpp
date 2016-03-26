/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Symbol.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 15:44:11 by leeios            #+#    #+#             */
/*   Updated: 2016/03/26 16:09:40 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOL_HPP
# define SYMBOL_HPP

enum class	eValue
{
	UNDEFINED = 0,
	CACULATING,
	TRUE,
	FALSE,
	ERROR
};

class Symbol
{
public:
	Symbol(const eValue val) : m_val(val) {};
	virtual ~Symbol(void) {};
	inline eValue		getVal(void) const {return (m_val);};
	inline eValue		getValNegative(bool neg) const
	{
		if (neg == false)
			return (m_val);
		switch (m_val)
		{
			case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
			case (eValue::CACULATING) : return (eValue::CACULATING);
			case (eValue::TRUE) : return (eValue::FALSE);
			case (eValue::FALSE) : return (eValue::TRUE);
			case (eValue::ERROR) : return (eValue::ERROR);
		};
	};

	inline eValue		operator&&(const Symbol &rightOp) const
	{
		switch (m_val)
		{
			case (eValue::UNDEFINED) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::CACULATING) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::UNDEFINED);
					case (eValue::FALSE) : return (eValue::UNDEFINED);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::CACULATING) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::CACULATING) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::UNDEFINED);
					case (eValue::FALSE) : return (eValue::UNDEFINED);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::TRUE) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::CACULATING) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::TRUE);
					case (eValue::FALSE) : return (eValue::FALSE);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::FALSE) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::CACULATING) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::FALSE);
					case (eValue::FALSE) : return (eValue::FALSE);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::ERROR) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::ERROR);
					case (eValue::CACULATING) : return (eValue::ERROR);
					case (eValue::TRUE) : return (eValue::ERROR);
					case (eValue::FALSE) : return (eValue::ERROR);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
		}
	};

	inline eValue		operator||(const Symbol &rightOp) const
	{
		switch (m_val)
		{
			case (eValue::UNDEFINED) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::CACULATING) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::UNDEFINED);
					case (eValue::FALSE) : return (eValue::UNDEFINED);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::CACULATING) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::CACULATING) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::UNDEFINED);
					case (eValue::FALSE) : return (eValue::UNDEFINED);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::TRUE) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::CACULATING) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::TRUE);
					case (eValue::FALSE) : return (eValue::TRUE);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::FALSE) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::CACULATING) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::TRUE);
					case (eValue::FALSE) : return (eValue::FALSE);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::ERROR) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::ERROR);
					case (eValue::CACULATING) : return (eValue::ERROR);
					case (eValue::TRUE) : return (eValue::ERROR);
					case (eValue::FALSE) : return (eValue::ERROR);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
		}
	};

	inline eValue		operator^(const Symbol &rightOp) const
	{
		switch (m_val)
		{
			case (eValue::UNDEFINED) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::CACULATING) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::UNDEFINED);
					case (eValue::FALSE) : return (eValue::UNDEFINED);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::CACULATING) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::CACULATING) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::UNDEFINED);
					case (eValue::FALSE) : return (eValue::UNDEFINED);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::TRUE) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::CACULATING) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::FALSE);
					case (eValue::FALSE) : return (eValue::TRUE);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::FALSE) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::CACULATING) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::TRUE);
					case (eValue::FALSE) : return (eValue::FALSE);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::ERROR) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::ERROR);
					case (eValue::CACULATING) : return (eValue::ERROR);
					case (eValue::TRUE) : return (eValue::ERROR);
					case (eValue::FALSE) : return (eValue::ERROR);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
		}
	};

private:
	const eValue		m_val;
};

#endif
