/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_each.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 19:38:40 by leeios            #+#    #+#             */
/*   Updated: 2016/09/16 20:27:55 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_FOR_EACH_H
# define TUPLE_FOR_EACH_H

# include <tuple>

namespace tuple
{
	template<std::size_t I = 0, typename FuncT, typename... Tp>
	inline typename std::enable_if<I == sizeof...(Tp), void>::type
	for_each(std::tuple<Tp...> &, FuncT) // Unused arguments are given no names.
	{}
	template<std::size_t I = 0, typename FuncT, typename... Tp>
	inline typename std::enable_if<I == sizeof...(Tp), void>::type
	for_each(std::tuple<Tp...> &&, FuncT) // Unused arguments are given no names.
	{}
	template<std::size_t I = 0, typename FuncT, typename... Tp>
	inline typename std::enable_if<I == sizeof...(Tp), void>::type
	for_each(const std::tuple<Tp...> &, FuncT) // Unused arguments are given no names.
	{}
	template<std::size_t I = 0, typename FuncT, typename... Tp>
	inline typename std::enable_if<I < sizeof...(Tp), void>::type
	for_each(std::tuple<Tp...>& t, FuncT f)
	{
		f(std::get<I>(t), I);
		for_each<I + 1, FuncT, Tp...>(t, f);
	}
	template<std::size_t I = 0, typename FuncT, typename... Tp>
	inline typename std::enable_if<I < sizeof...(Tp), void>::type
	for_each(std::tuple<Tp...>&& t, FuncT f)
	{
		f(std::get<I>(std::move(t)), I);
		for_each<I + 1, FuncT, Tp...>(std::move(t), f);
	}
	template<std::size_t I = 0, typename FuncT, typename... Tp>
	inline typename std::enable_if<I < sizeof...(Tp), void>::type
	for_each(const std::tuple<Tp...>& t, FuncT f)
	{
		f(std::get<I>(t), I);
		for_each<I + 1, FuncT, Tp...>(t, f);
	}

	template<std::size_t I = 0, typename FuncT, typename... Tp>
	inline typename std::enable_if<I == sizeof...(Tp), void>::type
	for_each_both(std::tuple<Tp...> &, const std::tuple<Tp...> &, FuncT)
	{}
	template<std::size_t I = 0, typename FuncT, typename... Tp>
	inline typename std::enable_if<I == sizeof...(Tp), void>::type
	for_each_both(std::tuple<Tp...> &&, const std::tuple<Tp...> &, FuncT)
	{}
	template<std::size_t I = 0, typename FuncT, typename... Tp>
	inline typename std::enable_if<I == sizeof...(Tp), void>::type
	for_each_both(const std::tuple<Tp...> &, const std::tuple<Tp...> &, FuncT)
	{}
	template<std::size_t I = 0, typename FuncT, typename... Tp>
	inline typename std::enable_if<I < sizeof...(Tp), void>::type
	for_each_both(std::tuple<Tp...>& t, const std::tuple<Tp...>& u, FuncT f)
	{
		f(std::get<I>(t), std::get<I>(u), I);
		for_each_both<I + 1, FuncT, Tp...>(t, u, f);
	}
	template<std::size_t I = 0, typename FuncT, typename... Tp>
	inline typename std::enable_if<I < sizeof...(Tp), void>::type
	for_each_both(std::tuple<Tp...>&& t, const std::tuple<Tp...>& u, FuncT f)
	{
		f(std::get<I>(std::move(t)), std::get<I>(std::move(u)), I);
		for_each_both<I + 1, FuncT, Tp...>(std::move(t), std::move(u), f);
	}
	template<std::size_t I = 0, typename FuncT, typename... Tp>
	inline typename std::enable_if<I < sizeof...(Tp), void>::type
	for_each_both(const std::tuple<Tp...>& t, const std::tuple<Tp...>& u, FuncT f)
	{
		f(std::get<I>(t), std::get<I>(u), I);
		for_each_both<I + 1, FuncT, Tp...>(t, u, f);
	}
};

#endif
