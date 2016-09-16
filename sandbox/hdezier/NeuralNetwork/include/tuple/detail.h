/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detail.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 19:27:38 by leeios            #+#    #+#             */
/*   Updated: 2016/09/16 20:37:22 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_DETAIL_H
# define TUPLE_DETAIL_H

# include <utility>

namespace tuple
{
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
		template <class F, std::size_t... Is>
		constexpr auto index_apply_impl(F &&f, std::index_sequence<Is...>)
		{
			return f(std::integral_constant<std::size_t, Is> {}...);
		}
		template <std::size_t N, class F>
		constexpr auto index_apply(F &&f)
		{
			return (index_apply_impl(f, std::make_index_sequence<N>{}));
		}
		template <std::size_t Begin, std::size_t End, class F>
		constexpr auto index_apply(F &&f)
		{
			return (index_apply_impl(f, make_index_range<Begin, End>{}));

		}
	};

};

#endif
