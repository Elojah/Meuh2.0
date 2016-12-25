/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zip.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 16:40:32 by leeios            #+#    #+#             */
/*   Updated: 2016/12/25 23:12:21 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_ZIP_H
# define TUPLE_ZIP_H

# include "tuple/detail.h"
# include <tuple>

namespace tuple
{
	// zip_with
	template<typename F, typename Tuple, typename...Tuples>
	inline constexpr auto	zip_with(F &&f, Tuple &&t, Tuples&&...ts)
	{
		const auto row =
		[&](auto I)
		{
			return (f(std::get<I>(std::move(t)), std::get<I>(std::move(ts))...));
		};
		return (detail::index_apply<std::tuple_size<Tuple>::value>(
		[&](auto&&...Is)
		{
			return (std::make_tuple(row(Is)...));
		}));
	}
	// zip
	template<typename Tuple, typename...Tuples>
	inline constexpr auto	zip(Tuple &&t, Tuples&&...ts)
	{
		return (zip_with([](auto&&...ts)
		{
			return (std::make_tuple(std::move(ts)...));
		}, std::move(t), std::move(ts)...));
	}

};

#endif
