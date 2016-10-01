/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fold.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 19:26:42 by leeios            #+#    #+#             */
/*   Updated: 2016/10/02 01:35:03 by hdezier          ###   ########.fr       */
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
		inline constexpr auto	foldl_impl(F &&f, CurrentVal &val, TupleVal&...ts)
		{
			detail::sink {f, ts...};
			return (val);
		};
		template<class F, class CurrentVal, class... TupleVal
			, typename std::enable_if<(sizeof...(TupleVal) == 0), int>::type = 0>
		inline constexpr auto	foldl_impl(F &&f, CurrentVal &&val, TupleVal&&...ts)
		{
			detail::sink {f, ts...};
			return (val);
		};
		template<class F, class CurrentVal, class... TupleVal
			, typename std::enable_if<(sizeof...(TupleVal) == 0), int>::type = 0>
		inline constexpr auto	foldl_impl(F &&f, const CurrentVal &val, const TupleVal&...ts)
		{
			detail::sink {f, ts...};
			return (val);
		};
		template<class F, class CurrentVal, class... TupleVal
			, typename std::enable_if<(sizeof...(TupleVal) > 0), int>::type = 0>
		inline constexpr auto	foldl_impl(F &&f, CurrentVal &val, TupleVal&... ts)
		{
			return (f(val, detail::foldl_impl(f, ts...)));
		};
		template<class F, class CurrentVal, class... TupleVal
			, typename std::enable_if<(sizeof...(TupleVal) > 0), int>::type = 0>
		inline constexpr auto	foldl_impl(F &&f, CurrentVal &&val, TupleVal&&... ts)
		{
			return (f(val, detail::foldl_impl(f, ts...)));
		};
		template<class F, class CurrentVal, class... TupleVal
			, typename std::enable_if<(sizeof...(TupleVal) > 0), int>::type = 0>
		inline constexpr auto	foldl_impl(F &&f, const CurrentVal &val, const TupleVal&... ts)
		{
			return (f(val, detail::foldl_impl(f, ts...)));
		};

	// Foldr impl
		template<class F, class CurrentVal, class... TupleVal
			, typename std::enable_if<(sizeof...(TupleVal) == 0), int>::type = 0>
		inline constexpr auto	foldr_impl(F &&f, CurrentVal &val, TupleVal&...ts)
		{
			detail::sink {f, ts...};
			return (val);
		};
		template<class F, class CurrentVal, class... TupleVal
			, typename std::enable_if<(sizeof...(TupleVal) == 0), int>::type = 0>
		inline constexpr auto	foldr_impl(F &&f, CurrentVal &&val, TupleVal&&...ts)
		{
			detail::sink {f, ts...};
			return (val);
		};
		template<class F, class CurrentVal, class... TupleVal
			, typename std::enable_if<(sizeof...(TupleVal) == 0), int>::type = 0>
		inline constexpr auto	foldr_impl(F &&f, const CurrentVal &val, const TupleVal&...ts)
		{
			detail::sink {f, ts...};
			return (val);
		};
		template<class F, class CurrentVal, class... TupleVal
			, typename std::enable_if<(sizeof...(TupleVal) > 0), int>::type = 0>
		inline constexpr auto	foldr_impl(F &&f, CurrentVal &val, TupleVal&... ts)
		{
			return (f(detail::foldr_impl(f, ts...), val));
		};
		template<class F, class CurrentVal, class... TupleVal
			, typename std::enable_if<(sizeof...(TupleVal) > 0), int>::type = 0>
		inline constexpr auto	foldr_impl(F &&f, CurrentVal &&val, TupleVal&&... ts)
		{
			return (f(detail::foldr_impl(f, ts...), val));
		};
		template<class F, class CurrentVal, class... TupleVal
			, typename std::enable_if<(sizeof...(TupleVal) > 0), int>::type = 0>
		inline constexpr auto	foldr_impl(F &&f, const CurrentVal &val, const TupleVal&... ts)
		{
			return (f(detail::foldr_impl(f, ts...), val));
		};

	};

// Foldl
	#include <iostream>
	#include "tuple/for_each.h"
	template <class Tuple, class F>
	inline constexpr auto	foldl(Tuple &t, F &&f)
	{
		for_each(t, [](const auto &elem, const auto &key){(void)key;std::cerr << elem.get() << "  /  ";});
		std::cerr << std::endl;
		return (apply(t, [&f](auto&...ts) { return (detail::foldl_impl(f, ts...)); }));
	}
	template <class Tuple, class F>
	inline constexpr auto	foldl(Tuple &&t, F &&f)
	{
		for_each(t, [](const auto &elem, const auto &key){(void)key;std::cerr << elem.get() << "  /  ";});
		std::cerr << std::endl;
		return (apply(std::move(t), [&f](auto&&...ts) { return (detail::foldl_impl(f, ts...)); }));
	}
	template <class Tuple, class F>
	inline constexpr auto	foldl(const Tuple &t, F &&f)
	{
		for_each(t, [](const auto &elem, const auto &key){(void)key;std::cerr << elem.get() << "  /  ";});
		std::cerr << std::endl;
		return (apply(t, [&f](const auto&...ts) { return (detail::foldl_impl(f, ts...)); }));
	}

// Foldr
	template <class Tuple, class F>
	inline constexpr auto	foldr(Tuple &t, F &&f)
	{
		return apply(t, [&f](auto&...ts) { return (detail::foldr_impl(f, ts...)); });
	}
	template <class Tuple, class F>
	inline constexpr auto	foldr(Tuple &&t, F &&f)
	{
		return apply(std::move(t), [&f](auto&&...ts) { return (detail::foldr_impl(f, ts...)); });
	}
	template <class Tuple, class F>
	inline constexpr auto	foldr(const Tuple &t, F &&f)
	{
		return apply(t, [&f](const auto&...ts) { return (detail::foldr_impl(f, ts...)); });
	}
};


#endif
