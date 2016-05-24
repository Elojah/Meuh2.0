/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_helper.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 14:17:11 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/24 14:26:56 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_HELPER_H
# define TYPE_HELPER_H

# include "Tokens.h"

# include <cmath>
# include <fenv.h>
# include <iostream>
# include <limits>
# include <sstream>
# include <stdexcept>

namespace	helper
{

	template<typename U>
	static inline std::string	_toStr(const U &value)
	{
		if (std::is_same<U, int8_t>::value
			|| std::is_same<U, int16_t>::value
			|| std::is_same<U, int32_t>::value)
			return (std::to_string(value));
		std::ostringstream	ss;
		ss << value;
		return (ss.str());
	};

	template<typename U>
	static inline U				_toType(const std::string &value)
	{
		U						result;

		try
		{
			if (std::is_same<U, int8_t>::value
				|| std::is_same<U, int16_t>::value
				|| std::is_same<U, int32_t>::value)
				result = std::stoi(value);
			else if (std::is_same<U, float>::value)
				result = std::stof(value);
			else if (std::is_same<U, double>::value)
				result = std::stod(value);
		}
		catch (const std::invalid_argument &e) {throw (eErr::INVALID_ARG);}
		catch (const std::out_of_range &e) {throw (eErr::OVERFLOW_INIT);}
		return (result);
	};

	struct			sAdd
	{
		template<typename U>
		static inline U			operate(const std::string &lhs, const std::string &rhs)
		{
			U					result;
			U					lhsValue;
			U					rhsValue;
			U					lhsOverflowLimit;
			static const U		nullValue(0.0);

			feclearexcept(FE_OVERFLOW);
			lhsValue = _toType<U>(lhs);
			rhsValue = _toType<U>(rhs);
			result = lhsValue + rhsValue;
			if (lhsValue > nullValue)
				lhsOverflowLimit = std::numeric_limits<U>::max() - std::abs(rhsValue);
			else
				lhsOverflowLimit = std::abs(std::numeric_limits<U>::min() + std::abs(rhsValue));
			if (fetestexcept(FE_OVERFLOW)
				|| (((lhsValue > nullValue) == (rhsValue > nullValue))
					&& std::abs(lhsValue) > lhsOverflowLimit))
				throw (eErr::OVERFLOW_CALC);
			return (result);
		}
	};
	struct			sSub
	{
		template<typename U>
		static inline U			operate(const std::string &lhs, const std::string &rhs)
		{
			U					result;
			U					lhsValue;
			U					rhsValue;
			U					lhsOverflowLimit;
			static const U		nullValue(0.0);

			feclearexcept(FE_OVERFLOW);
			lhsValue = _toType<U>(lhs);
			rhsValue = _toType<U>(rhs);
			result = lhsValue - rhsValue ;
			if (lhsValue > nullValue)
				lhsOverflowLimit = std::numeric_limits<U>::max() - std::abs(rhsValue);
			else
				lhsOverflowLimit = std::abs(std::numeric_limits<U>::min() + std::abs(rhsValue));
			if (fetestexcept(FE_OVERFLOW)
				|| (((lhsValue > nullValue) != (rhsValue > nullValue))
					&& std::abs(lhsValue) > lhsOverflowLimit))
				throw (eErr::OVERFLOW_CALC);
			return (result);
		}
	};
	struct			sMul
	{
		template<typename U>
		static inline U			operate(const std::string &lhs, const std::string &rhs)
		{
			U					result;
			U					lhsValue;
			U					rhsValue;
			static const U		nullValue(0.0);

			feclearexcept(FE_OVERFLOW);
			feclearexcept(FE_UNDERFLOW);
			lhsValue = _toType<U>(lhs);
			rhsValue = _toType<U>(rhs);
			result = lhsValue * rhsValue ;
			if (fetestexcept(FE_UNDERFLOW))
				throw (eErr::UNDERFLOW_CALC);
			else if (fetestexcept(FE_OVERFLOW)
				|| (lhsValue != nullValue && (std::numeric_limits<U>::max() / lhsValue) < rhsValue))
				throw (eErr::OVERFLOW_CALC);
			return (result);
		}
	};
	struct			sDiv
	{
		template<typename U>
		static inline U			operate(const std::string &lhs, const std::string &rhs)
		{
			U					result;
			U					lhsValue;
			U					rhsValue;
			static const U		nullValue(0.0);

			feclearexcept(FE_OVERFLOW);
			feclearexcept(FE_UNDERFLOW);
			lhsValue = _toType<U>(lhs);
			rhsValue = _toType<U>(rhs);
			if (rhsValue == nullValue)
				throw (eErr::DIV_BY_ZERO);
			result = lhsValue / rhsValue ;
			if (fetestexcept(FE_UNDERFLOW)
				|| (result == nullValue && lhsValue != nullValue)
				|| result * rhsValue != lhsValue)
				throw (eErr::UNDERFLOW_CALC);
			else if (fetestexcept(FE_OVERFLOW))
				throw (eErr::OVERFLOW_CALC);
			return (result);
		}
	};
	struct			sMod
	{
		template<typename U>
		static inline U			operate(const std::string &lhs, const std::string &rhs)
		{
			U					result;
			U					lhsValue;
			U					rhsValue;

			lhsValue = _toType<U>(lhs);
			rhsValue = _toType<U>(rhs);
			result = std::fmod(lhsValue, rhsValue);
			if (fetestexcept(FE_INVALID))
				throw (eErr::DIV_BY_ZERO);
			return (result);
		}
	};
};

#endif
