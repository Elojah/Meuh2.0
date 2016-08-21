/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 19:21:54 by leeios            #+#    #+#             */
/*   Updated: 2016/08/21 15:46:16 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_H
# define TUPLE_H

# include <tuple>
# include <utility>
# include <functional>
# include <type_traits>

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

// Helpers

	//http://stackoverflow.com/questions/20874388/error-spliting-an-stdindex-sequence
	namespace	detail
	{

		// Range index
		template <typename T, typename Seq, T Begin>
		struct make_integer_range_impl;
		template <typename T, T... Ints, T Begin>
		struct make_integer_range_impl<T, std::integer_sequence<T, Ints...>, Begin>
		{
			using type = std::integer_sequence<T, Begin + Ints...>;
		};
		/* Similar to std::make_integer_sequence<>, except it goes from [Begin, End)
		   instead of [0, End). */
		template <typename T, T Begin, T End>
		using make_integer_range = typename make_integer_range_impl<
			T, std::make_integer_sequence<T, End - Begin>, Begin>::type;
		/* Similar to std::make_index_sequence<>, except it goes from [Begin, End)
		   instead of [0, End). */
		template <std::size_t Begin, std::size_t End>
		using make_index_range = make_integer_range<std::size_t, Begin, End>;

		// http://aherrmann.github.io/programming/2016/02/28/unpacking-tuples-in-cpp14/
		template <class F, size_t... Is>
		constexpr auto index_apply_impl(F &&f, std::index_sequence<Is...>)
		{
			return f(std::integral_constant<size_t, Is> {}...);
		}
		template <size_t N, class F>
		constexpr auto index_apply(F &&f)
		{
			return (index_apply_impl(f, std::make_index_sequence<N>{}));
		}
		template <size_t Begin, std::size_t End, class F>
		constexpr auto index_apply(F &&f)
		{
			return (index_apply_impl(f, make_index_range<Begin, End>{}));
		}
	};

// Split tuple
	template<std::size_t Begin, std::size_t End, class Tuple>
	constexpr auto	split(const Tuple &t)
	{
		return (detail::index_apply<Begin, End>([&](auto...Is)
		{
			return (std::make_tuple(std::get<Is>(t)...));
		}));
	}
	template<std::size_t Begin, std::size_t End, class Tuple>
	constexpr auto	split(Tuple &&t)
	{
		return (detail::index_apply<Begin, End>([&](auto...Is)
		{
			return (std::forward_as_tuple(std::get<Is>(std::forward<Tuple>(t))...));
		}));
	}

// Map
	template <class Tuple, class F>
	inline constexpr auto	mapM(const Tuple &t, F f)
	{
		detail::index_apply<std::tuple_size<Tuple>{}>([&](auto...Is)
		{
			int	unused[] = {(f(std::get<Is>(t)), 0)...};
			(void)unused;
		});
	}
	template <class Tuple, class F>
	inline constexpr auto	map(const Tuple &t, F f)
	{
		return (detail::index_apply<std::tuple_size<Tuple>{}>([&](auto...Is)
		{
			return (std::make_tuple(f(std::get<Is>(t))...));
		}));
	}

// Apply
	template <class Tuple, class F>
	inline constexpr auto	apply(const Tuple &t, F f)
	{
		return (detail::index_apply<std::tuple_size<Tuple>{}>(
			[&](auto...Is) {return f(std::get<Is>(t)...); }));
	}


	namespace	detail
	{
		struct	sink
		{
			template<typename...Args>
			explicit sink(Args const &...) {};
		};

		template<class F, class CurrentVal, class... TupleVal>
		inline constexpr auto	foldl_impl(F &f, CurrentVal &val, TupleVal... ts
			, typename std::enable_if<(sizeof...(TupleVal) > 0)>::type* = nullptr)
		{
			return (f(val, foldl_impl(f, ts...)));
		};
		template<class F, class CurrentVal, class... TupleVal>
		inline constexpr auto	foldl_impl(F &f, CurrentVal &val, TupleVal&...ts
			, typename std::enable_if<(sizeof...(TupleVal) == 0)>::type* = nullptr)
		{
			detail::sink {f, ts...};
			return (val);
		};
	};

// Foldl
	template <class Tuple, class F>
	constexpr auto	foldl(const Tuple &t, F f)
	{
		return apply(t, [&f](auto... ts) { return (detail::foldl_impl(f, ts...)); });
	}

// Transpose
	template <class Tuple>
	inline constexpr auto	transpose(const Tuple &t)
	{
		return (apply(t, [](auto... ts) { return zip(ts...); }));
	}
	template <class... Tuples>
	inline constexpr auto	zip(Tuples... ts)
	{
		constexpr size_t len = std::min({std::tuple_size<Tuples>{}...});
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
	constexpr auto	zip() { return (std::make_tuple()); }

// Repeat type
	namespace	detail
	{
		template<typename Dependent, std::size_t Index>
		using DependOn = Dependent;
	};
	template<typename T, std::size_t N, typename Indices = std::make_index_sequence<N>>
	struct	repeat;
	template<typename T, std::size_t N, std::size_t... Indices>
	struct	repeat<T, N, std::index_sequence<Indices...>> {
		using type = std::tuple<detail::DependOn<T, Indices>...>;
	};

	template<std::size_t N, typename...Ts>
	using	tuple_repeat = repeat<std::tuple<Ts...>, N>;

	// template<class MergeF, class ExpandF, class TupleLhs, class TupleRhs>
	// inline auto		matrix_mult_tuple(const TupleLhs &lhs, const TupleRhs &rhs)
	// {
	// 	auto	do_calcul =
	// 	[](const auto &lhs, const auto &rhs)
	// 	{
	// 		;
	// 	};
	// 	// return (detail::index_apply<std::tuple_size<TupleLhs>{}>([&](auto...Is)
	// 	// {
	// 	// 	return (detail::index_apply<std::tuple_size<TupleRhs>{}>([&](auto...Js)
	// 	// 	{
	// 	// 		return (detail::index_apply<std::tuple_size<TupleLhs>{}>([&](auto...IIs)
	// 	// 		{
	// 	// 			return (detail::index_apply<std::tuple_size<TupleRhs>{}>([&](auto...JJs)
	// 	// 			{
	// 	// 				;
	// 	// 			}));
	// 	// 		}));
	// 	// 	}));
	// 	// }));
	// };

};

#endif
