/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 19:26:42 by leeios            #+#    #+#             */
/*   Updated: 2016/12/25 23:12:31 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_MAP_H
# define TUPLE_MAP_H

# include "tuple/detail.h"
# include <tuple>

namespace tuple
{
// Map
	template <typename Tuple, typename F>
	inline constexpr auto	map(Tuple &&t, F &&f)
	{
		return (detail::index_apply<std::tuple_size<Tuple>::value>([&](auto...Is)
		{
			return (std::make_tuple(f(std::get<Is>(std::move(t)))...));
		}));
	}
};

#endif
