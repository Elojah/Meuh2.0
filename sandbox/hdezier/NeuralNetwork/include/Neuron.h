/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Neuron.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 14:19:18 by leeios            #+#    #+#             */
/*   Updated: 2016/12/27 12:54:22 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEURON_H
# define NEURON_H

# include <iostream>
# include "tuple.h"

namespace	ErrorComputing
{
	template<typename...Ts>
	struct	SquaredError;
	template<typename TError, typename...TOutputs>
	struct	SquaredError<TError, std::tuple<TOutputs...>>
	{
		inline static TError	apply(const std::tuple<TOutputs...> &out
			, const std::tuple<TOutputs...> &target)
		{
			(void)out;
			(void)target;
		};
	};
};

namespace	NeuronTypes
{
	struct classic_test
	{
		constexpr static auto	coef_fn = tuple::mult;
		constexpr static auto	merge_fn = tuple::add;
		constexpr static auto	output_fn = tuple::pass;
		constexpr static float	sigma = 0.01;
	};
};

template<typename...Ts>
class		Neuron;
template<typename TType, typename...TInputs, typename...TOutputs>
class		Neuron<TType, std::tuple<TInputs...>, std::tuple<TOutputs...>>
{
public:
	Neuron(void) = default;
	~Neuron(void) = default;

	inline void						set_initial_params(const std::tuple<TInputs...> &params)
	{
		(void)params;
		// tuple::for_each(m_parameters, [&](auto &value, auto key) {
		// 	(void)key;
		// 	value = tuple::map(params, [&](const auto &value_j) {return (value_j);});
		// });
	};
	inline void						print_params(void)
	{
		// tuple::for_each(m_parameters, [&](auto &value, auto key) {
		// 	tuple::for_each(value, [&](auto &value_in, auto key_in) {
		// 		std::cout << "Value_" << key << "_" << key_in << " : " << value_in << std::endl;
		// 	});
		// });
		// tuple::for_each(m_parameters, [&](auto &value, const auto &key) { (void)key;
		// 	value = tuple::map(params, [&](const auto &value_j) {return (value_j);});
		// });
	};

	inline std::tuple<TOutputs...>	forward(const std::tuple<TInputs...> &&input_values) const
	{
		// Simple matrix multiplication
		return (TType::output_fn(
					tuple::mult(
						std::move(input_values), std::move(m_parameters), TType::merge_fn, TType::coef_fn
					)
				)
		);
	};

	inline std::tuple<TInputs...>	backward(const std::tuple<TOutputs...> &output_values)
	{
		(void)output_values;
		return (std::tuple<TInputs...>());
	};

private:
	/*
	** input := (x, y, z, ...)
	** params := ((xParam, yParam, zParam, ...), (xParam, yParam, zParam, ...), ...)
	** params_size := sizeof output
	** output := ({x * xParam + y * yParam + z * zParam}, {x * xParam + y * yParam + z * zParam}, ...)
	*/
	typedef std::tuple<TInputs...>										t_row;// Add bias here ?
	typedef typename tuple::repeat<t_row, sizeof...(TOutputs)>::type	t_params;

	t_params													m_parameters;
};

#endif
