/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 19:21:54 by leeios            #+#    #+#             */
/*   Updated: 2016/08/15 20:23:42 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef META_H
# define META_H

# include <tuple>
# include <utility>


namespace		meta
{
	namespace	type
	{
		// Store template package
		template <typename... Ts>
		struct variadic_typedef
		{
			// this single type represents a collection of types,
			// as the template arguments it took to define it
		};
		template <typename... Ts>
		struct convert_in_tuple
		{
			// base case, nothing special,
			// just use the arguments directly
			// however they need to be used
			typedef std::tuple<Ts...> type;
		};
		template <typename... Ts>
		struct convert_in_tuple<variadic_typedef<Ts...>>
		{
			// expand the variadic_typedef back into
			// its arguments, via specialization
			// (doesn't rely on functionality to be provided
			// by the variadic_typedef struct itself, generic)
			typedef typename convert_in_tuple<Ts...>::type type;
		};
		template<typename...Ts>
		using types = convert_in_tuple<variadic_typedef<Ts...>>;

	// Head list
		template<typename...Ts>
		struct		head {};
		template<typename T>
		struct		head<T>
		{
			using type = typename T::type;
		};
		template<typename T, typename...Ts>
		struct		head<T, Ts...>
		{
			using type = typename T::type;
		};

	// Last list
		template <class... Ts>
		struct last {};
		template <typename T>
		struct last<T>
		{
			using type = typename T::type;
		};
		template <class T, class... Ts>
		struct last<T, Ts...>
		{
			using type = typename last<Ts...>::type;
		};

	// Tail list
		template <class... Ts>
		struct tail {};
		template <class T, class... Ts>
		struct tail<T, Ts...>
		{
			using type = typename types<Ts...>::type;
		};

	// Revert variadic types
		template<typename, typename>
		struct revert_type_seq_impl {};
		template<typename T, typename... Ts>
		struct revert_type_seq_impl<T, std::tuple<Ts...>>
		{
			using type = typename std::tuple<Ts..., T>::type;
		};
		template<typename... Ts>
		struct revert_type_seq
		{
			using type = std::tuple<>;
		};
		template<typename T, typename... Ts>
		struct revert_type_seq<T, Ts...>
		{
			using type = typename revert_type_seq_impl<T, revert_type_seq<Ts...>>::type;
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
	namespace	tuple
	{
		;
	};
};


#endif
