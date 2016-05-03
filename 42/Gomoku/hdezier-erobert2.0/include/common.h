/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 21:25:52 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/03 01:40:43 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "stdint.h"

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

};

#endif
