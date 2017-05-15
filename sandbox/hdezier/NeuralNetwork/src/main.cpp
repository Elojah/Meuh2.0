/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 14:58:38 by leeios            #+#    #+#             */
/*   Updated: 2017/05/08 16:12:49 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "tuple.h"
#include "Neuron.h"
#include <typeinfo>
#include <cassert>

#ifdef TEST

static void	test_neuron(void)
{
	std::cout << "_________________________ NEURON" << std::endl;
	typedef typename tuple::repeat<Feature::Test, 4>::type		t_inputs;
	typedef typename tuple::repeat<int, 2>::type				t_outputs;
	Neuron<NeuronTypes::classic_test, t_inputs, t_outputs>		n;
	n.set_initial_params(std::make_tuple(
			tuple::map(std::make_tuple(52, 98, 14, 32), tuple::convert<Feature::Test>),
			tuple::map(std::make_tuple(74, 85, 95, 65), tuple::convert<Feature::Test>)
		));
	const auto out = n.forward(tuple::map(std::make_tuple(36, 15, 78, 95), tuple::convert<Feature::Test>));
	tuple::print(std::move(out));
}

static void	exec(void)
{
	// typedef std::tuple<int, float, double>				t_inputs;
	// typedef typename tuple::repeat<double, 4>::type		t_inputs;
	// typedef typename tuple::repeat<double, 2>::type		t_outputs;

	const auto	tb = std::make_tuple(Feature::Test(1), Feature::Test(2)
		, Feature::Test(3), Feature::Test(4));
	const auto	ta = std::make_tuple(Feature::Test(1), Feature::Test(2)
		, Feature::Test(3), Feature::Test(4));
	const auto	tc = std::make_tuple(Feature::Test(1), Feature::Test(2)
		, Feature::Test(3), Feature::Test(4));
	std::cout << "_________________________ FOR_EACH" << std::endl;
	tuple::for_each([](auto &&a, auto &&b, auto &&c) -> auto
	{
		assert(a == b);
		assert(a == c);
		std::cout << a << std::endl;
		// return (std::move(a));
	}, std::move(ta), std::move(tb), std::move(tc));
	int		i = 1;
	tuple::for_each([&](auto &&a) -> auto
	{
		assert(a == i);
		i++;
		// return (a);
	}, std::move(ta));
	std::cout << "_________________________ MAP" << std::endl;
	const auto td = tuple::map(std::move(ta), [](auto &&a)
	{
		return (std::move(a) * Feature::Test(2));
	});
	i = 1;
	tuple::for_each([&](auto &&d) -> auto
	{
		assert(d == i * 2);
		i++;
		// return (d);
	}, std::move(td));
	std::cout << "_________________________ FOLD" << std::endl;
	assert(-8 == tuple::foldl(std::move(ta), [](auto &&a, auto &&b)
	{
		return (std::move(a) - std::move(b));
	}));
	assert(-2 == tuple::foldr(std::move(tb), [](auto &&a, auto &&b)
	{
		return (std::move(a) - std::move(b));
	}));
	std::cout << "_________________________ ZIP" << std::endl;
	assert(
		tuple::foldl(
			tuple::zip_with(
				std::move(tuple::mult), std::move(ta), std::move(tb), std::move(tc)
			)
			, [](auto &&a, auto &&b)
			{
				return (std::move(a) + std::move(b));
		})
	== 100);
	const auto te = tuple::zip(std::move(ta), std::move(tb));
	std::cout << "_________________________ MISC" << std::endl;
	const auto tf = tuple::foldl(std::move(te), [](auto &&lhs, auto &&rhs) -> auto
	{
		return (std::make_tuple(
			std::get<0>(std::move(lhs)) + std::get<0>(std::move(rhs)), std::get<1>(std::move(lhs)) - std::get<1>(std::move(rhs)))
		);
	});
	assert(std::get<0>(std::move(tf)) == 10 && std::get<1>(std::move(tf)) == -8);
	std::cout << "_________________________ TRANSPOSE" << std::endl;
	const auto tg = std::make_tuple(std::move(ta), std::move(tb), std::move(tc));
	(void)tg;
	const auto th = tuple::transpose(std::move(tg));
	(void)th;
	std::cout << "_________________________ MULT" << std::endl;
	const auto ti = tuple::mult_tuple(std::move(ta), std::move(tg), std::move(tuple::add), std::move(tuple::mult));
	(void)ti;
	const auto	taa = std::make_tuple(Feature::Test(1), Feature::Test(2), Feature::Test(3));
	const auto tj = tuple::mult_tuple(std::move(taa), std::move(th), std::move(tuple::add), std::move(tuple::mult));
	(void)tj;
	tuple::for_each([](auto &&t)
	{
		tuple::print(std::move(t));
	}, std::move(tg));
	tuple::for_each([](auto &&t)
	{
		tuple::print(std::move(t));
	}, std::move(th));
	tuple::print(std::move(ti));
	tuple::print(std::move(tj));
	test_neuron();
}

#else

static void	exec(void)
{
	std::cout << "PASS" << std::endl;
}

#endif

//#include <variant>
int			main(int ac, char **av)
{
//	std::variant<int, float> a;
//	(void)a;
	(void)ac;
	(void)av;
	exec();
	return (0);
}
