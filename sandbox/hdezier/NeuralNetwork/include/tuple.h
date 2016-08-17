/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 19:21:54 by leeios            #+#    #+#             */
/*   Updated: 2016/08/17 17:16:42 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_H
# define TUPLE_H

# include <tuple>
# include <utility>

namespace	tuple
{
	template<std::size_t I = 0, typename FuncT, typename... Tp>
	inline typename std::enable_if<I == sizeof...(Tp), void>::type
	for_each(std::tuple<Tp...> &, FuncT) // Unused arguments are given no names.
	{}

	template<std::size_t I = 0, typename FuncT, typename... Tp>
	inline typename std::enable_if<I < sizeof...(Tp), void>::type
	for_each(std::tuple<Tp...>& t, FuncT f)
	{
		f(std::get<I>(t), I);
		for_each<I + 1, FuncT, Tp...>(t, f);
	}

	template<std::size_t I = 0, typename FuncT, typename... Tp>
	inline typename std::enable_if<I == sizeof...(Tp), void>::type
	for_each_both_const(const std::tuple<Tp...> &, const std::tuple<Tp...> &, FuncT)
	{}

	template<std::size_t I = 0, typename FuncT, typename... Tp>
	inline typename std::enable_if<I < sizeof...(Tp), void>::type
	for_each_both_const(const std::tuple<Tp...>& t, const std::tuple<Tp...>& u, FuncT f)
	{
		f(std::get<I>(t), std::get<I>(u), I);
		for_each_both_const<I + 1, FuncT, Tp...>(t, u, f);
	}
};

#endif
