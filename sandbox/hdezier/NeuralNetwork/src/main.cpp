/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 14:58:38 by leeios            #+#    #+#             */
/*   Updated: 2016/12/25 18:25:51 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "tuple.h"
#include "Neuron.h"
#include <cassert>

static void	test_exec(void)
{
	// typedef std::tuple<int, float, double>				t_inputs;
	typedef typename tuple::repeat<double, 4>::type		t_inputs;
	// typedef typename tuple::repeat<double, 2>::type		t_outputs;

	const t_inputs	ta = std::make_tuple(1, 2, 3, 4);
	const t_inputs	tb = std::make_tuple(1, 2, 3, 4);
	const t_inputs	tc = std::make_tuple(1, 2, 3, 4);
	tuple::for_each([](auto &&a, auto &&b, auto &&c) -> auto
	{
		assert(a == b);
		assert(a == c);
		return (a + b - c);
	}, std::move(ta), std::move(tb), std::move(tc));
	int		i = 1;
	tuple::for_each([&](auto &&a) -> auto
	{
		assert(a == i);
		i++;
		return (a);
	}, std::move(ta));
	const auto td = tuple::map(std::move(ta), [](auto &&a)
	{
		return (std::move(a) * 2);
	});
	i = 1;
	tuple::for_each([&](auto &&d) -> auto
	{
		assert(d == i * 2);
		i++;
		return (d);
	}, std::move(td));
	assert(-13 == tuple::foldl(std::make_tuple(1, 2, 3, 4, 5), [](auto &&a, auto &&b)
	{
		return (std::move(a) - std::move(b));
	}));
	assert(-2 == tuple::foldr(std::move(tb), [](auto &&a, auto &&b)
	{
		return (std::move(a) - std::move(b));
	}));
	assert(tuple::foldl(tuple::zip_with([](auto &&a, auto &&b, auto &&c)
		{
			return (a * b * c);
		}, std::move(ta), std::move(tb), std::move(tc)), [](auto &&a, auto &&b)
	{
		return (a + b);
	}) == 100);
}

int			main(int ac, char **av)
{
	(void)ac;
	(void)av;
	test_exec();
	return (0);
}
