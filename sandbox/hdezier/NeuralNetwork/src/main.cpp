/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 14:58:38 by leeios            #+#    #+#             */
/*   Updated: 2016/10/02 01:37:44 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "tuple.h"
#include "Neuron.h"
#include <iostream>

static void	exec(void)
{
	// typedef std::tuple<int, float, double>				t_inputs;
	typedef typename tuple::repeat<Feature::Test, 2>::type			t_inputs;
	typedef typename tuple::repeat<float, 2>::type					t_outputs;

	Neuron<char, t_inputs, t_outputs>		neuron;
	neuron.set_initial_params(std::make_tuple(Feature::Test(0), Feature::Test(1)));
	t_inputs	input(Feature::Test(2), Feature::Test(100));
	const auto output = neuron.forward(input);
	tuple::for_each(output, [](const auto &value, const auto &key)
	{
		std::cout << key << " -> " << value << std::endl;
	});
}

int			main(int ac, char **av)
{
	(void)ac;
	(void)av;
	exec();
	return (0);
}
