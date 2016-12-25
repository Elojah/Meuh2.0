/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpose.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 19:38:34 by leeios            #+#    #+#             */
/*   Updated: 2016/12/25 18:25:57 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_TRANSPOSE_H
# define TUPLE_TRANSPOSE_H

# include "tuple/detail.h"
# include "tuple/zip.h"

namespace tuple
{
// Transpose
	template <class Tuple>
	inline constexpr auto	transpose(Tuple &&t)
	{
		return (apply(std::move(t), [](auto&&...ts) { return zip(std::move(ts)...); }));
	}

};

#endif
