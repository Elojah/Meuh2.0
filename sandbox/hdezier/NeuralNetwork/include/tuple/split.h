/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 19:38:30 by leeios            #+#    #+#             */
/*   Updated: 2016/12/27 13:26:05 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_SPLIT_H
# define TUPLE_SPLIT_H

# include "tuple/detail.h"
# include <tuple>

namespace tuple
{
// Split tuple
	template<std::size_t Begin, std::size_t End, class Tuple>
	static inline constexpr auto	split(Tuple const &&t)
	{
		return (detail::index_apply<Begin, End>([&](auto...Is)
		{
			return (std::forward_as_tuple(std::get<Is>(std::move(t))...));
		}));
	}
};

#endif
