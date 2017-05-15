/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 12:10:56 by leeios            #+#    #+#             */
/*   Updated: 2016/12/24 14:43:11 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nn.h"
#include <cassert>

static void	test_fold(void)
{
	const auto t = std::make_tuple(1, 2, 3, 4, 5);
	const auto u = std::make_tuple(1, 2, 3, 4, 5);
	assert(nn::fold_with(std::move(t), std::move(u), [](auto &&lhs, auto &&rhs)
	{
		return (std::move(lhs + rhs));
	}) == 30);
}

int		main(int argc, char const *argv[])
{
	(void)argc;
	(void)argv;
	test_fold();
	return 0;
}
