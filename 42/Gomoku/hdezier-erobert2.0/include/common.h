/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 21:25:52 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/03 03:55:01 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "stdint.h"

# define OPPONENT(n) ((n) == common::eCell::P1 ? common::eCell::P2 : common::eCell::P1)

namespace common
{

	static const uint8_t	small = 9;
	static const uint8_t	medium = 13;
	static const uint8_t	large = 19;

	enum class eCell
	{
		NONE = 0,
		P1,
		P2,
		E_CELL
	};

	struct				vec2
	{
		uint8_t			x;
		uint8_t			y;
	};

	enum class eDirection
	{
		U = 1,
		UR = 2,
		R = 3,
		DR = 4,
		D = -1,
		DL = -2,
		L = -3,
		UL = -4
	};

	inline eDirection		opposite(const eDirection &dir)
	{
		switch (dir)
		{
			case (eDirection::U) : return (eDirection::D);
			case (eDirection::UR) : return (eDirection::DL);
			case (eDirection::R) : return (eDirection::L);
			case (eDirection::DR) : return (eDirection::UL);
			case (eDirection::D) : return (eDirection::U);
			case (eDirection::DL) : return (eDirection::UR);
			case (eDirection::L) : return (eDirection::R);
			case (eDirection::UL) : return (eDirection::DR);
		}
	}

};

#endif
