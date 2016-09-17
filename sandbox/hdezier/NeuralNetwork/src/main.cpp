/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 14:58:38 by leeios            #+#    #+#             */
/*   Updated: 2016/09/17 16:57:55 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "tuple.h"
#include "Neuron.h"


static void	exec(void)
{
	// typedef std::tuple<int, float, double>				t_inputs;
	typedef typename tuple::repeat<double, 7>::type		t_inputs;
	typedef typename tuple::repeat<float, 7>::type		t_outputs;

	Neuron<char, t_inputs, t_outputs>		neuron;
	t_inputs	seed;
	tuple::mapM(seed, [](auto &value) {value = 1;});
	t_inputs	input;
	tuple::mapM(input, [](auto &value) {value = 2.5;});
	neuron.set_initial_params(std::make_tuple(1, 1, 1, 1, 1, 1, 1));
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
