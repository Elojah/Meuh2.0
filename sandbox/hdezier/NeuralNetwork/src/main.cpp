/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 14:58:38 by leeios            #+#    #+#             */
/*   Updated: 2016/12/26 13:15:11 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "tuple.h"
#include "Neuron.h"
#include <typeinfo>
#include <cassert>

static void	test_exec(void)
{
	// typedef std::tuple<int, float, double>				t_inputs;
	// typedef typename tuple::repeat<double, 4>::type		t_inputs;
	// typedef typename tuple::repeat<double, 2>::type		t_outputs;

	const auto	ta = std::make_tuple(1, 2, 3, 4);
	const auto	tb = std::make_tuple(1, 2, 3, 4);
	const auto	tc = std::make_tuple(1, 2, 3, 4);
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
	assert(
		tuple::foldl(
			tuple::zip_with(
				tuple::mult, std::move(ta), std::move(tb), std::move(tc)
			)
			, [](auto &&a, auto &&b)
			{
				return (std::move(a) + std::move(b));
		})
	== 100);
	const auto te = tuple::zip(std::move(ta), std::move(tb));
	const auto tf = tuple::foldl(std::move(te), [](auto &&lhs, auto &&rhs) -> auto
	{
		return (std::make_tuple(std::get<0>(lhs) + std::get<0>(rhs), std::get<1>(lhs) - std::get<1>(rhs)));
	});
	assert(std::get<0>(tf) == 10 && std::get<1>(tf) == -8);
	const auto tg = std::make_tuple(ta, tb, tc);
	const auto th = tuple::transpose(tg);
	const auto ti = tuple::mult_tuple(std::move(ta), std::move(tg), tuple::add, tuple::mult);
	tuple::for_each([](auto &&t)
	{
		tuple::print(std::move(t));
	}, std::move(tg));
	tuple::for_each([](auto &&t)
	{
		tuple::print(std::move(t));
	}, std::move(th));
	tuple::print(std::move(ti));
}

int			main(int ac, char **av)
{
	(void)ac;
	(void)av;
	test_exec();
	return (0);
}
