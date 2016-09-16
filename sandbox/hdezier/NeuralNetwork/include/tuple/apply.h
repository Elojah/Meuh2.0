/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 19:26:42 by leeios            #+#    #+#             */
/*   Updated: 2016/09/16 20:26:54 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_APPLY_H
# define TUPLE_APPLY_H

# include "tuple/detail.h"

namespace tuple
{
// Apply
	template <class Tuple, class F>
	inline constexpr auto	apply(Tuple &t, F &&f)
	{
		return (detail::index_apply<std::tuple_size<Tuple>{}>(
			[&](auto...Is) {return f(std::get<Is>(t)...); }));
	}
	template <class Tuple, class F>
	inline constexpr auto	apply(Tuple &&t, F &&f)
	{
		return (detail::index_apply<std::tuple_size<Tuple>{}>(
			[&](auto...Is) {return f(std::get<Is>(std::move(t))...); }));
	}
	template <class Tuple, class F>
	inline constexpr auto	apply(const Tuple &t, F &&f)
	{
		return (detail::index_apply<std::tuple_size<Tuple>{}>(
			[&](auto...Is) {return f(std::get<Is>(t)...); }));
	}
};

#endif
