/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 14:58:38 by leeios            #+#    #+#             */
/*   Updated: 2016/08/17 17:16:49 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "tuple.h"
#include "Neuron.h"
#include <typeinfo>


static void	exec(void)
{
	typedef std::tuple<int, float>										t_inputs;
	typedef std::tuple<float, float, float>								t_outputs;
	typedef NeuronTypes::Parametrable<Functors::Mult, Functors::Add>	t_linear_neuron;

	Neuron<t_linear_neuron, t_inputs, t_outputs>	neuron;

	t_inputs	init_params{3, 5};
	neuron.set_initial_params(init_params);

	t_inputs	test{1, 2};
	const auto	result_test = neuron.forward(test);
	std::cerr << "Result: " << std::get<0>(result_test) << " / "
	<< std::get<1>(result_test) << " / "
	<< std::get<2>(result_test) << std::endl;
}

int			main(int ac, char **av)
{
	(void)ac;
	(void)av;
	exec();
	return (0);
}
