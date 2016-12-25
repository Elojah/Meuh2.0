/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fold.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 19:26:42 by leeios            #+#    #+#             */
/*   Updated: 2016/12/24 16:28:04 by leeios           ###   ########.fr       */
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
		inline constexpr auto	foldl_impl(F &&f, CurrentVal &&val, TupleVal&&...ts)
		{
			detail::sink {f, ts...};
			return (std::move(val));
		};
		template<class F, class CurrentVal, class NextVal, class... TupleVal>
		inline constexpr auto	foldl_impl(F &&f, CurrentVal &&val, NextVal &&next, TupleVal&&... ts)
		{
			return (detail::foldl_impl(std::move(f), f(std::move(val), std::move(next)), std::move(ts)...));
		};

	// Foldr impl
		template<class F, class CurrentVal, class... TupleVal
			, typename std::enable_if<(sizeof...(TupleVal) == 0), int>::type = 0>
		inline constexpr auto	foldr_impl(F &&f, CurrentVal &&val, TupleVal&&...ts)
		{
			detail::sink {f, ts...};
			return (std::move(val));
		};
		template<class F, class CurrentVal, class... TupleVal
			, typename std::enable_if<(sizeof...(TupleVal) > 0), int>::type = 0>
		inline constexpr auto	foldr_impl(F &&f, CurrentVal &&val, TupleVal&&... ts)
		{
			return (f(detail::foldr_impl(std::move(f), std::move(ts)...), std::move(val)));
		};
	};

// Foldl
	template <class Tuple, class F>
	inline constexpr auto	foldl(Tuple &&t, F &&f)
	{
		return (apply(std::move(t), [&f](auto&&...ts) { return (detail::foldl_impl(std::move(f), std::move(ts)...)); }));
	}

// Foldr
	template <class Tuple, class F>
	inline constexpr auto	foldr(Tuple &&t, F &&f)
	{
		return (apply(std::move(t), [&f](auto&&...ts) { return (detail::foldr_impl(std::move(f), std::move(ts)...)); }));
	}
};


#endif
