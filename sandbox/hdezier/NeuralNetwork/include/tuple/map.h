/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 19:26:42 by leeios            #+#    #+#             */
/*   Updated: 2016/10/02 01:38:33 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_MAP_H
# define TUPLE_MAP_H

# include "tuple/detail.h"
# include <tuple>

namespace tuple
{
// Map
	template <class Tuple, class F>
	inline constexpr auto	mapM(Tuple &t, F &&f)
	{
		detail::index_apply<std::tuple_size<Tuple>{}>([&](auto...Is)
		{
			int	unused[] = {(f(std::get<Is>(t)), 0)...};
			(void)unused;
		});
	}
	template <class Tuple, class F>
	inline constexpr auto	mapM(Tuple &&t, F &&f)
	{
		detail::index_apply<std::tuple_size<Tuple>{}>([&](auto...Is)
		{
			int	unused[] = {(f(std::get<Is>(std::move(t))), 0)...};
			(void)unused;
		});
	}
	template <class Tuple, class F>
	inline constexpr auto	mapM(const Tuple &t, F &&f)
	{
		detail::index_apply<std::tuple_size<Tuple>{}>([&](auto...Is)
		{
			int	unused[] = {(f(std::get<Is>(t)), 0)...};
			(void)unused;
		});
	}
	template <class Tuple, class F>
	inline constexpr auto	map(Tuple &t, F &&f)
	{
		return (detail::index_apply<std::tuple_size<Tuple>{}>([&](auto...Is)
		{
			return (std::make_tuple(f(std::get<Is>(t))...));
		}));
	}
	template <class Tuple, class F>
	inline constexpr auto	map(Tuple &&t, F &&f)
	{
		return (detail::index_apply<std::tuple_size<Tuple>{}>([&](auto...Is)
		{
			return (std::make_tuple(f(std::get<Is>(std::move(t)))...));
		}));
	}
	template <class Tuple, class F>
	inline constexpr auto	map(const Tuple &t, F &&f)
	{
		return (detail::index_apply<std::tuple_size<Tuple>{}>([&](auto...Is)
		{
			return (std::make_tuple(f(std::get<Is>(t))...));
		}));
	}
};

#endif
