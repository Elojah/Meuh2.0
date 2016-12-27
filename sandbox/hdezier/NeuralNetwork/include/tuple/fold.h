/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fold.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 19:26:42 by leeios            #+#    #+#             */
/*   Updated: 2016/12/27 12:59:00 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_FOLD_H
# define TUPLE_FOLD_H

#include "tuple/detail.h"
#include "tuple/apply.h"

namespace	tuple
{
	namespace	detail
	{
		struct	sink
		{
			template<typename...Args>
			explicit sink(Args const &...) {};
		};

	// Foldl impl
		template<class F, class CurrentVal, class... TupleVal
			, typename std::enable_if<(sizeof...(TupleVal) == 0), int>::type = 0>
		static inline constexpr auto	foldl_impl(F &&f, CurrentVal const &&val, TupleVal const&&...ts)
		{
			detail::sink {f, ts...};
			return (std::move(val));
		};
		template<class F, class CurrentVal, class NextVal, class... TupleVal>
		static inline constexpr auto	foldl_impl(F &&f, CurrentVal const &&val, NextVal const &&next, TupleVal const&&... ts)
		{
			return (detail::foldl_impl(std::move(f), f(std::move(val), std::move(next)), std::move(ts)...));
		};

	// Foldr impl
		template<class F, class CurrentVal, class... TupleVal
			, typename std::enable_if<(sizeof...(TupleVal) == 0), int>::type = 0>
		static inline constexpr auto	foldr_impl(F &&f, CurrentVal const &&val, TupleVal const&&...ts)
		{
			detail::sink {f, ts...};
			return (std::move(val));
		};
		template<class F, class CurrentVal, class... TupleVal
			, typename std::enable_if<(sizeof...(TupleVal) > 0), int>::type = 0>
		static inline constexpr auto	foldr_impl(F &&f, CurrentVal const &&val, TupleVal const&&... ts)
		{
			return (f(detail::foldr_impl(std::move(f), std::move(ts)...), std::move(val)));
		};
	};

// Foldl
	template <class Tuple, class F>
	static inline constexpr auto	foldl(Tuple const &&t, F &&f)
	{
		return (apply(std::move(t), [&f](auto&&...ts) { return (detail::foldl_impl(std::move(f), std::move(ts)...)); }));
	}

// Foldr
	template <class Tuple, class F>
	static inline constexpr auto	foldr(Tuple const &&t, F &&f)
	{
		return (apply(std::move(t), [&f](auto&&...ts) { return (detail::foldr_impl(std::move(f), std::move(ts)...)); }));
	}
};

#endif
