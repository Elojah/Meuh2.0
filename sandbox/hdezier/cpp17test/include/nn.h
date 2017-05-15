/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nn.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 12:14:05 by leeios            #+#    #+#             */
/*   Updated: 2016/12/24 14:55:13 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <experimental/tuple>
#include <tuple>

namespace	nn
{

	// template<typename F>
	// inline constexpr auto		lambda(F &&fn)
	// {
	// 	return ([&](auto&&...args) -> auto
	// 	{
	// 		return (fn(args...));
	// 	});
	// }

	// template<typename F, typename Arg>
	// inline constexpr auto		curry(F &&fn, Arg &&arg)
	// {
	// 	return ([&](auto&&...args) -> auto
	// 	{
	// 		return (fn(arg, args...));
	// 	});
	// }

	template<typename F, typename Tl, typename Tr>
	inline constexpr auto		fold_with(Tl &&lhs, Tr &&rhs, F &&fn)
	{
		return (std::experimental::apply(([=](auto&&...argsl) -> auto
		{
			return (std::experimental::apply(([=](auto&&...argsr) -> auto
			{
				return (fn(argsl, argsr) + ...);
			}), std::forward<Tr>(rhs)));
		}), std::forward<Tl>(lhs)));
	};
};
