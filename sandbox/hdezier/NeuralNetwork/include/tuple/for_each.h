/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_each.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 19:38:40 by leeios            #+#    #+#             */
/*   Updated: 2016/12/25 23:12:36 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_FOR_EACH_H
# define TUPLE_FOR_EACH_H

# include <tuple>

namespace tuple
{

	template<std::size_t I = 0, typename F, typename Tuple, typename...Tuples>
	inline typename std::enable_if<I == std::tuple_size<Tuple>::value, void>::type
	for_each(F &&, Tuple &&, Tuples&&...)
	{}
	template<std::size_t I = 0, typename F, typename Tuple, typename...Tuples>
	inline typename std::enable_if<I < std::tuple_size<Tuple>::value, void>::type
	constexpr for_each(F &&f, Tuple &&t, Tuples&&...ts)
	{
		f(std::get<I>(std::move(t)), std::get<I>(std::move(ts))...);
		for_each<I + 1, F>(std::move(f), std::move(t), std::move(ts)...);
	}

};

#endif
