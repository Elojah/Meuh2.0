/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 14:58:38 by leeios            #+#    #+#             */
/*   Updated: 2016/08/21 14:18:47 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "tuple.h"
#include "Neuron.h"


static void	exec(void)
{
	typedef std::tuple<int, float>										t_inputs;
	typedef std::tuple<float, float, float, float>						t_outputs;
	typedef NeuronTypes::Parametrable<Functors::Mult, Functors::Add>	t_linear_neuron;

	Neuron<t_linear_neuron, t_inputs, t_outputs>	neuron;

	t_inputs	init_params{3, 5};
	t_outputs	out_params{11, 5, 9, 32};
	neuron.set_initial_params(init_params);

	std::tuple<int, char, float, char, double>	test_tuple = std::make_tuple(1, 'a', 3.14, 'z', 5.8);
	auto tuple_splitted = tuple::split<1, 3>(std::move(test_tuple));
	(void)tuple_splitted;

	auto	result = tuple::foldl(out_params
		, [](auto &a, auto &b)
		{
			return (a + b);
		});
	std::cout << "Foldl result: " << result << std::endl;
	// t_inputs	test{1, 2};
	// auto		result_test = neuron.forward(test);

	tuple::map(tuple_splitted, [](auto &value) -> int
	{
		std::cerr << value << "/" << std::endl;
		return (0);
	});

	tuple::map(test_tuple, [](auto &value)
	{
		std::cerr << value << "/" << std::endl;
		return (0);
	});

	tuple::mapM(tuple_splitted, [](auto &value) -> void
	{
		std::cerr << value << "/" << std::endl;
	});
}

int			main(int ac, char **av)
{
	(void)ac;
	(void)av;
	exec();
	return (0);
}
