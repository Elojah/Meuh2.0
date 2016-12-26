/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 12:46:26 by leeios            #+#    #+#             */
/*   Updated: 2016/12/26 13:11:09 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_MULT_H
# define TUPLE_MULT_H

# include "tuple/fold.h"

namespace tuple
{

template<typename TLhs, typename TRhs, typename FFold, typename FZip>
inline constexpr auto	mult_tuple(TLhs &&lhs, TRhs &&rhs, FFold &&fnFold, FZip &&fnZip)
{
	return	(map
				(std::move(rhs), [&](auto &&v)
					{
						return	(foldl
									(zip_with
										(fnZip, std::move(lhs), std::move(v))
									, fnFold));
					}
				)
			);
}

};

#endif
