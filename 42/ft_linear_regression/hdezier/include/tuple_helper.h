/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   tuple_helper.h									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: leeios <leeios@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2016/08/15 00:16:20 by leeios			#+#	#+#			 */
/*   Updated: 2016/08/15 00:59:27 by leeios		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef TUPLE_HELPER_H
# define TUPLE_HELPER_H

# include <tuple>
# include <utility>

namespace tuple_helper
{

// For each tuple
	template<std::size_t I = 0, typename FuncT, typename... Tp>
	inline typename std::enable_if<I == sizeof...(Tp), void>::type
	for_each(std::tuple<Tp...> &, FuncT) // Unused arguments are given no names.
	{}

	template<std::size_t I = 0, typename FuncT, typename... Tp>
	inline typename std::enable_if<I < sizeof...(Tp), void>::type
	for_each(std::tuple<Tp...>& t, FuncT f)
	{
		f(std::get<I>(t));
		for_each<I + 1, FuncT, Tp...>(t, f);
	}

// Store template package
	template <typename... Args>
	struct variadic_typedef
	{
		// this single type represents a collection of types,
		// as the template arguments it took to define it
	};
	template <typename... Args>
	struct convert_in_tuple
	{
		// base case, nothing special,
		// just use the arguments directly
		// however they need to be used
		typedef std::tuple<Args...> type;
	};
	template <typename... Args>
	struct convert_in_tuple<variadic_typedef<Args...>>
	{
		// expand the variadic_typedef back into
		// its arguments, via specialization
		// (doesn't rely on functionality to be provided
		// by the variadic_typedef struct itself, generic)
		typedef typename convert_in_tuple<Args...>::type type;
	};

	template<typename...Ts>
	using types = typename convert_in_tuple<variadic_typedef<Ts...>>::type;
};

#endif
