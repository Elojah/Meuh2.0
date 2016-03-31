/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Symbol.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 15:44:11 by leeios            #+#    #+#             */
/*   Updated: 2016/03/31 19:23:54 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOL_HPP
# define SYMBOL_HPP

#include <string>

enum class	eValue
{
	UNDEFINED = 0,
	TRUE,
	TRUE_TEST,
	FALSE,
	FALSE_TEST,
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
			case (eValue::TRUE) : return (eValue::FALSE);
			case (eValue::FALSE) : return (eValue::TRUE);
			case (eValue::TRUE_TEST) : return (eValue::FALSE_TEST);
			case (eValue::FALSE_TEST) : return (eValue::TRUE_TEST);
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
					case (eValue::TRUE) : return (eValue::UNDEFINED);
					case (eValue::FALSE) : return (eValue::UNDEFINED);
					case (eValue::TRUE_TEST) : return (eValue::UNDEFINED);
					case (eValue::FALSE_TEST) : return (eValue::UNDEFINED);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::TRUE) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::TRUE);
					case (eValue::FALSE) : return (eValue::FALSE);
					case (eValue::TRUE_TEST) : return (eValue::TRUE_TEST);
					case (eValue::FALSE_TEST) : return (eValue::FALSE_TEST);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::FALSE) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::FALSE);
					case (eValue::FALSE) : return (eValue::FALSE);
					case (eValue::TRUE_TEST) : return (eValue::FALSE_TEST);
					case (eValue::FALSE_TEST) : return (eValue::FALSE_TEST);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::TRUE_TEST) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::TRUE_TEST);
					case (eValue::FALSE) : return (eValue::FALSE_TEST);
					case (eValue::TRUE_TEST) : return (eValue::TRUE_TEST);
					case (eValue::FALSE_TEST) : return (eValue::FALSE_TEST);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::FALSE_TEST) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::FALSE_TEST);
					case (eValue::FALSE) : return (eValue::FALSE_TEST);
					case (eValue::TRUE_TEST) : return (eValue::FALSE_TEST);
					case (eValue::FALSE_TEST) : return (eValue::FALSE_TEST);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::ERROR) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::ERROR);
					case (eValue::TRUE) : return (eValue::ERROR);
					case (eValue::FALSE) : return (eValue::ERROR);
					case (eValue::TRUE_TEST) : return (eValue::ERROR);
					case (eValue::FALSE_TEST) : return (eValue::ERROR);
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
					case (eValue::TRUE) : return (eValue::UNDEFINED);
					case (eValue::FALSE) : return (eValue::UNDEFINED);
					case (eValue::TRUE_TEST) : return (eValue::UNDEFINED);
					case (eValue::FALSE_TEST) : return (eValue::UNDEFINED);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::TRUE) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::TRUE);
					case (eValue::FALSE) : return (eValue::TRUE);
					case (eValue::TRUE_TEST) : return (eValue::TRUE_TEST);
					case (eValue::FALSE_TEST) : return (eValue::TRUE_TEST);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::FALSE) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::TRUE);
					case (eValue::FALSE) : return (eValue::FALSE);
					case (eValue::TRUE_TEST) : return (eValue::TRUE_TEST);
					case (eValue::FALSE_TEST) : return (eValue::FALSE_TEST);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::TRUE_TEST) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::TRUE_TEST);
					case (eValue::FALSE) : return (eValue::TRUE_TEST);
					case (eValue::TRUE_TEST) : return (eValue::TRUE_TEST);
					case (eValue::FALSE_TEST) : return (eValue::TRUE_TEST);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::FALSE_TEST) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::TRUE_TEST);
					case (eValue::FALSE) : return (eValue::FALSE_TEST);
					case (eValue::TRUE_TEST) : return (eValue::TRUE_TEST);
					case (eValue::FALSE_TEST) : return (eValue::FALSE_TEST);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::ERROR) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::ERROR);
					case (eValue::TRUE) : return (eValue::ERROR);
					case (eValue::FALSE) : return (eValue::ERROR);
					case (eValue::TRUE_TEST) : return (eValue::ERROR);
					case (eValue::FALSE_TEST) : return (eValue::ERROR);
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
					case (eValue::TRUE) : return (eValue::UNDEFINED);
					case (eValue::FALSE) : return (eValue::UNDEFINED);
					case (eValue::TRUE_TEST) : return (eValue::UNDEFINED);
					case (eValue::FALSE_TEST) : return (eValue::UNDEFINED);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::TRUE) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::FALSE);
					case (eValue::FALSE) : return (eValue::TRUE);
					case (eValue::TRUE_TEST) : return (eValue::FALSE_TEST);
					case (eValue::FALSE_TEST) : return (eValue::TRUE_TEST);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::FALSE) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::TRUE);
					case (eValue::FALSE) : return (eValue::FALSE);
					case (eValue::TRUE_TEST) : return (eValue::TRUE_TEST);
					case (eValue::FALSE_TEST) : return (eValue::FALSE_TEST);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::TRUE_TEST) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::FALSE_TEST);
					case (eValue::FALSE) : return (eValue::TRUE_TEST);
					case (eValue::TRUE_TEST) : return (eValue::FALSE_TEST);
					case (eValue::FALSE_TEST) : return (eValue::TRUE_TEST);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::FALSE_TEST) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::TRUE_TEST);
					case (eValue::FALSE) : return (eValue::FALSE_TEST);
					case (eValue::TRUE_TEST) : return (eValue::TRUE_TEST);
					case (eValue::FALSE_TEST) : return (eValue::FALSE_TEST);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::ERROR) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::ERROR);
					case (eValue::TRUE) : return (eValue::ERROR);
					case (eValue::FALSE) : return (eValue::ERROR);
					case (eValue::TRUE_TEST) : return (eValue::ERROR);
					case (eValue::FALSE_TEST) : return (eValue::ERROR);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
		}
	};


	inline eValue		operator==(const Symbol &rightOp) const
	{
		switch (m_val)
		{
			case (eValue::UNDEFINED) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::UNDEFINED);
					case (eValue::FALSE) : return (eValue::UNDEFINED);
					case (eValue::TRUE_TEST) : return (eValue::UNDEFINED);
					case (eValue::FALSE_TEST) : return (eValue::UNDEFINED);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::TRUE) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::TRUE);
					case (eValue::FALSE) : return (eValue::FALSE);
					case (eValue::TRUE_TEST) : return (eValue::TRUE_TEST);
					case (eValue::FALSE_TEST) : return (eValue::FALSE_TEST);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::FALSE) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::FALSE);
					case (eValue::FALSE) : return (eValue::TRUE);
					case (eValue::TRUE_TEST) : return (eValue::FALSE_TEST);
					case (eValue::FALSE_TEST) : return (eValue::TRUE_TEST);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::TRUE_TEST) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::TRUE_TEST);
					case (eValue::FALSE) : return (eValue::FALSE_TEST);
					case (eValue::TRUE_TEST) : return (eValue::TRUE_TEST);
					case (eValue::FALSE_TEST) : return (eValue::FALSE_TEST);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::FALSE_TEST) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::FALSE_TEST);
					case (eValue::FALSE) : return (eValue::TRUE_TEST);
					case (eValue::TRUE_TEST) : return (eValue::FALSE_TEST);
					case (eValue::FALSE_TEST) : return (eValue::TRUE_TEST);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::ERROR) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::ERROR);
					case (eValue::TRUE) : return (eValue::ERROR);
					case (eValue::FALSE) : return (eValue::ERROR);
					case (eValue::TRUE_TEST) : return (eValue::ERROR);
					case (eValue::FALSE_TEST) : return (eValue::ERROR);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
		}
	};

	inline eValue		operator!=(const Symbol &rightOp) const
	{
		switch (m_val)
		{
			case (eValue::UNDEFINED) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::UNDEFINED);
					case (eValue::FALSE) : return (eValue::UNDEFINED);
					case (eValue::TRUE_TEST) : return (eValue::UNDEFINED);
					case (eValue::FALSE_TEST) : return (eValue::UNDEFINED);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::TRUE) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::FALSE);
					case (eValue::FALSE) : return (eValue::TRUE);
					case (eValue::TRUE_TEST) : return (eValue::FALSE_TEST);
					case (eValue::FALSE_TEST) : return (eValue::TRUE_TEST);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::FALSE) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::TRUE);
					case (eValue::FALSE) : return (eValue::FALSE);
					case (eValue::TRUE_TEST) : return (eValue::TRUE_TEST);
					case (eValue::FALSE_TEST) : return (eValue::FALSE_TEST);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::TRUE_TEST) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::FALSE_TEST);
					case (eValue::FALSE) : return (eValue::TRUE_TEST);
					case (eValue::TRUE_TEST) : return (eValue::FALSE_TEST);
					case (eValue::FALSE_TEST) : return (eValue::TRUE_TEST);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::FALSE_TEST) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
					case (eValue::TRUE) : return (eValue::TRUE_TEST);
					case (eValue::FALSE) : return (eValue::FALSE_TEST);
					case (eValue::TRUE_TEST) : return (eValue::TRUE_TEST);
					case (eValue::FALSE_TEST) : return (eValue::FALSE_TEST);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
			case (eValue::ERROR) :
				switch (rightOp.getVal())
				{
					case (eValue::UNDEFINED) : return (eValue::ERROR);
					case (eValue::TRUE) : return (eValue::ERROR);
					case (eValue::FALSE) : return (eValue::ERROR);
					case (eValue::TRUE_TEST) : return (eValue::ERROR);
					case (eValue::FALSE_TEST) : return (eValue::ERROR);
					case (eValue::ERROR) : return (eValue::ERROR);
				}
		}
	};

	inline bool		asBool(void) const
	{
		switch (m_val)
		{
			case (eValue::UNDEFINED) : return (false);
			case (eValue::TRUE) : return (true);
			case (eValue::FALSE) : return (false);
			case (eValue::TRUE_TEST) : return (true);
			case (eValue::FALSE_TEST) : return (false);
			case (eValue::ERROR) : return (false);
		}
	};

	inline static eValue opposite(const eValue val, bool negative)
	{
		if (!negative)
			return (val);
		switch (val)
		{
			case (eValue::UNDEFINED) : return (eValue::UNDEFINED);
			case (eValue::TRUE) : return (eValue::FALSE);
			case (eValue::FALSE) : return (eValue::TRUE);
			case (eValue::TRUE_TEST) : return (eValue::FALSE_TEST);
			case (eValue::FALSE_TEST) : return (eValue::TRUE_TEST);
			case (eValue::ERROR) : return (eValue::ERROR);
		}
	};

	inline static const std::string	getName(eValue val)
	{
		static const std::string	valueNames[(int)eValue::ERROR + 1] =
		{
			"UNDEFINED",
			"TRUE",
			"TRUE_TEST",
			"FALSE",
			"FALSE_TEST",
			"ERROR"
		};
		return (valueNames[(int)val]);
	};

private:
	const eValue				m_val;
};


#endif
