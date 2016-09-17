/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zip.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 16:40:32 by leeios            #+#    #+#             */
/*   Updated: 2016/09/17 16:43:21 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_ZIP_H
# define TUPLE_ZIP_H

# include "tuple/detail.h"
# include <tuple>

namespace tuple
{
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

	// zipWith
	template<class Tuple, class F>
	inline constexpr auto	zipWith(Tuple &lhs, Tuple &rhs, F &&f)
	{
		return (detail::index_apply<std::tuple_size<Tuple>{}>([&](auto...Is)
		{
			return (std::make_tuple(f(std::get<Is>(lhs), std::get<Is>(rhs))...));
		}));
	}
	template<class Tuple, class F>
	inline constexpr auto	zipWith(Tuple &&lhs, Tuple &&rhs, F &&f)
	{
		return (detail::index_apply<std::tuple_size<Tuple>{}>([&](auto...Is)
		{
			return (std::make_tuple(f(std::get<Is>(lhs), std::get<Is>(rhs))...));
		}));
	}
	template<class Tuple, class F>
	inline constexpr auto	zipWith(const Tuple &lhs, const Tuple &rhs, F &&f)
	{
		return (detail::index_apply<std::tuple_size<Tuple>{}>([&](auto...Is)
		{
			return (std::make_tuple(f(std::get<Is>(lhs), std::get<Is>(rhs))...));
		}));
	}

};

#endif
