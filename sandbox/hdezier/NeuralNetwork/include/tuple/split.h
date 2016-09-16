/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 19:38:30 by leeios            #+#    #+#             */
/*   Updated: 2016/09/16 20:26:25 by leeios           ###   ########.fr       */
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
	constexpr auto	split(Tuple &t)
	{
		return (detail::index_apply<Begin, End>([&](auto...Is)
		{
			return (std::forward_as_tuple(std::get<Is>(t)...));
		}));
	}
	template<std::size_t Begin, std::size_t End, class Tuple>
	constexpr auto	split(Tuple &&t)
	{
		return (detail::index_apply<Begin, End>([&](auto...Is)
		{
			return (std::forward_as_tuple(std::get<Is>(std::move(t))...));
		}));
	}
	template<std::size_t Begin, std::size_t End, class Tuple>
	constexpr auto	split(const Tuple &t)
	{
		return (detail::index_apply<Begin, End>([&](auto...Is)
		{
			return (std::make_tuple(std::get<Is>(t)...));
		}));
	}
};

#endif
