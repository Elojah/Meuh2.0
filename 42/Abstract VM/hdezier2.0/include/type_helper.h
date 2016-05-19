/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_helper.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 14:17:11 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/19 19:03:49 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_HELPER_H
# define TYPE_HELPER_H

# include "Tokens.h"

# include <cmath>
# include <iostream>

namespace	helper
{
	template<typename U>
	static inline U					_convertTo(const std::string &value)
	{
		U						result;
		if (std::is_same<U, int8_t>::value
			|| std::is_same<U, int16_t>::value
			|| std::is_same<U, int32_t>::value)
			result = std::atoi(value.c_str());
		else if (std::is_same<U, float>::value)
			result = std::atof(value.c_str());
		else if (std::is_same<U, double>::value)
			result = std::atol(value.c_str());
		return (result);
	};

	struct			sAdd
	{
		template<typename U>
		static inline U			operate(const std::string &lhs, const std::string &rhs)
		{
			return (_convertTo<U>(lhs) + _convertTo<U>(rhs));
		}
	};
	struct			sSub
	{
		template<typename U>
		static inline U			operate(const std::string &lhs, const std::string &rhs)
		{
			return (_convertTo<U>(lhs) - _convertTo<U>(rhs));
		}
	};
	struct			sMul
	{
		template<typename U>
		static inline U			operate(const std::string &lhs, const std::string &rhs)
		{
			return (_convertTo<U>(lhs) * _convertTo<U>(rhs));
		}
	};
	struct			sDiv
	{
		template<typename U>
		static inline U			operate(const std::string &lhs, const std::string &rhs)
		{
			auto	convertedRhs = _convertTo<U>(rhs);
			if (convertedRhs == 0)
			{
				std::cerr << "Div by zero !" << std::endl;
				throw (eErr::DIV_BY_ZERO);
			}
			return (_convertTo<U>(lhs) / convertedRhs);
		}
	};
	struct			sMod
	{
		template<typename U>
		static inline U			operate(const std::string &lhs, const std::string &rhs)
		{
			auto	convertedRhs = _convertTo<U>(rhs);
			if (convertedRhs == 0)
				throw (eErr::DIV_BY_ZERO);
			return (std::fmod(_convertTo<U>(lhs), convertedRhs));
		}
	};
};

#endif
