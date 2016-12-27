/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lambda.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/25 19:31:38 by leeios            #+#    #+#             */
/*   Updated: 2016/12/27 13:50:09 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAMBDA_H
# define LAMBDA_H

# include <tuple>

namespace tuple
{

	static const auto	add = [](auto&&...ts)
	{
		return (std::move(ts) + ...);
	};
	static const auto	sub = [](auto&&...ts)
	{
		return (std::move(ts) + ...);
	};
	static const auto	mult = [](auto&&...ts)
	{
		return (std::move(ts) * ...);
	};
	static const auto	div = [](auto&&...ts)
	{
		return (std::move(ts) / ...);
	};
	static const auto	mod = [](auto&&...ts)
	{
		return (std::move(ts) % ...);
	};
	static const auto	pass = [](auto&& t)
	{
		return (std::move(t));
	};

};

#endif
