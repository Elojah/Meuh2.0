/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fold2D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 15:52:40 by leeios            #+#    #+#             */
/*   Updated: 2016/09/17 16:47:29 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_FOLD2D_H
# define TUPLE_FOLD2D_H

# include "tuple/detail.h"
# include "tuple/fold.h"
# include "tuple/zip.h"

namespace tuple
{
// Matrix mult
	template <typename Lhs, typename Rhs, typename FRow, typename FCol>
	inline constexpr auto	fold2D(const Lhs &lhs, const Rhs &rhs
		, FRow && f_row, FCol && f_col)
	{
		return (map(rhs, [&](const auto &value) {
			return (foldl(zipWith(lhs, value, f_row), f_col));
		}));
	}
}
#endif
