/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpose.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 19:38:34 by leeios            #+#    #+#             */
/*   Updated: 2016/09/16 20:28:17 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_TRANSPOSE_H
# define TUPLE_TRANSPOSE_H

# include "tuple/detail.h"
# include <tuple>

namespace tuple
{
// Transpose
	template <class Tuple>
	inline constexpr auto	transpose(Tuple &t)
	{
		return (apply(t, [](auto... ts) { return zip(ts...); }));
	}
	template <class Tuple>
	inline constexpr auto	transpose(Tuple &&t)
	{
		return (apply(std::move(t), [](auto... ts) { return zip(ts...); }));
	}
	template <class Tuple>
	inline constexpr auto	transpose(const Tuple &t)
	{
		return (apply(t, [](auto... ts) { return zip(ts...); }));
	}
// Zip
	template <class... Tuples>
	inline constexpr auto	zip(Tuples&...ts)
	{
		constexpr std::size_t len = std::min({std::tuple_size<Tuples>{}...});
		auto row =
		[&](auto I)
		{
			return (std::make_tuple(std::get<I>(ts)...));
		};
		return (detail::index_apply<len>(
		[&](auto... Is)
		{
			return (std::make_tuple(row(Is)...));
		}));
	}
	template <class... Tuples>
	inline constexpr auto	zip(Tuples&&...ts)
	{
		constexpr std::size_t len = std::min({std::tuple_size<Tuples>{}...});
		auto row =
		[&](auto I)
		{
			return (std::make_tuple(std::get<I>(std::move(ts))...));
		};
		return (detail::index_apply<len>(
		[&](auto... Is)
		{
			return (std::make_tuple(row(std::move(Is))...));
		}));
	}
	template <class... Tuples>
	inline constexpr auto	zip(const Tuples&...ts)
	{
		constexpr std::size_t len = std::min({std::tuple_size<Tuples>{}...});
		auto row =
		[&](auto I)
		{
			return (std::make_tuple(std::get<I>(ts)...));
		};
		return (detail::index_apply<len>(
		[&](auto... Is)
		{
			return (std::make_tuple(row(Is)...));
		}));
	}
	inline constexpr auto	zip() { return (std::make_tuple()); }
};

#endif
