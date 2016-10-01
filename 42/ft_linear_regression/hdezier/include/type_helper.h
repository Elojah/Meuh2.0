/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::	*/
/*	type_helper.h									 :+:	  :+:	:+:	*/
/*													+:+ +:+		 +:+	 */
/*	By: leeios <leeios@student.42.fr>			  +#+  +:+		+#+		*/
/*												+#+#+#+#+#+	+#+			*/
/*	Created: 2016/08/15 00:16:20 by leeios			#+#	#+#			 */
/*	Updated: 2016/08/15 00:59:27 by leeios			###	########.fr		*/
/*																			*/
/* ************************************************************************** */

#ifndef type_helper_H
# define type_helper_H

# include <tuple>
# include <utility>

namespace type_helper
{
	template<typename T , typename... Ts>
	auto head( std::tuple<T,Ts...> t )
	{
		return  std::get<0>(t);
	}

	template < std::size_t... Ns , typename... Ts >
	auto tail_impl( std::index_sequence<Ns...> , std::tuple<Ts...> t )
	{
		return  std::make_tuple( std::get<Ns+1u>(t)... );
	}

	template < typename... Ts >
	auto tail( std::tuple<Ts...> t )
	{
		return  tail_impl( std::make_index_sequence<sizeof...(Ts) - 1u>() , t );
	}

// For each tuple
	template<std::size_t I = 0, typename FuncT, typename... Tp>
	inline typename std::enable_if<I == sizeof...(Tp), void>::type
	for_each(std::tuple<Tp...> &, FuncT) // Unused arguments are given no names.
	{}

	template<std::size_t I = 0, typename FuncT, typename... Tp>
	inline typename std::enable_if<I <sizeof...(Tp), void>::type
	for_each(std::tuple<Tp...>& t, FuncT f)
	{
		f(std::get<I>(t));
		for_each<I + 1, FuncT, Tp...>(t, f);
	}

// Revert variadic types
	template<typename, typename>
	struct concat_seq {};
	template<typename T, typename... Ts>
	struct concat_seq<T, std::tuple<Ts...>>
	{
		using type = std::tuple<Ts..., T>;
	};
	template<typename... Ts>
	struct revert_type_seq
	{
		using type = std::tuple<>;
	};
	template<typename T, typename... Ts>
	struct revert_type_seq<T, Ts...>
	{
		using type = typename concat_seq<
			T,
			typename revert_type_seq<Ts...>::type
		>::type;
	};
// Select all but last of variadic template
	template<int ...i> struct seq{};
	template<int s, typename I, typename J> struct concate;
	template<int s, int ...i, int ...j>
	struct concate<s, seq<i...>, seq<j...>>
	{
		typedef seq<i..., (s + j)...> type;
	};
	template<int n> struct make_seq_impl;
	template<int n> using make_seq = typename make_seq_impl<n>::type;
	template<> struct make_seq_impl<0>{ typedef seq<> type;};
	template<> struct make_seq_impl<1>{ typedef seq<0> type;};
	template<int n> struct make_seq_impl: concate<n/2, make_seq<n/2>, make_seq<n-n/2>>{};

	template<std::size_t ...> struct index_sequence{};
	template<typename IndexSequence> struct pop_back;
	// empty index_sequence
	template<>struct pop_back<index_sequence<>>
	{
		typedef index_sequence<> type;
	};
	template<std::size_t ...i>
	struct pop_back<index_sequence<i...>>
	{
		static constexpr std::size_t size = sizeof...(i);
		static constexpr std::size_t values[] = {i...};
		template<typename sq> struct apply;
		template<int ...j> struct apply<seq<j...>>
		{
			typedef index_sequence<values[j]...> type;
		};
		typedef typename apply<make_seq<size - 1>>::type type;
	};
};

#endif
