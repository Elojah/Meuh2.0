/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 19:46:36 by leeios            #+#    #+#             */
/*   Updated: 2016/09/16 19:47:41 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_REPEAT_H
# define TUPLE_REPEAT_H

# include <utility>

namespace tuple
{
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
};

#endif
