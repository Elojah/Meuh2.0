/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Neuron.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 14:19:18 by leeios            #+#    #+#             */
/*   Updated: 2017/05/08 19:02:50 by leeios           ###   ########.fr       */
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
		static decltype(tuple::mult)		coef_fn;
		static decltype(tuple::div)			back_coef_fn;
		static decltype(tuple::add)			merge_fn;
		static decltype(tuple::sub)			back_merge_fn;
		static decltype(tuple::pass)		output_fn;
		static decltype(tuple::pass)		back_output_fn;
		constexpr const static float		sigma = 0.01;
	};
	decltype(tuple::mult) classic_test::coef_fn = tuple::mult;
	decltype(tuple::div) classic_test::back_coef_fn = tuple::div;
	decltype(tuple::add) classic_test::merge_fn = tuple::add;
	decltype(tuple::sub) classic_test::back_merge_fn = tuple::sub;
	decltype(tuple::pass) classic_test::output_fn = tuple::pass;
	decltype(tuple::pass) classic_test::back_output_fn = tuple::pass;
};

template<typename...Ts>
class		Neuron;
template<typename TType, typename...TInputs, typename...TOutputs>
class		Neuron<TType, std::tuple<TInputs...>, std::tuple<TOutputs...>>
{
public:

	/*
	** input := (x, y, z, ...)
	** params := ((xParam, yParam, zParam, ...), (xParam, yParam, zParam, ...), ...)
	** params_size := sizeof output
	** output := ({x * xParam + y * yParam + z * zParam}, {x * xParam + y * yParam + z * zParam}, ...)
	*/
	typedef std::tuple<TInputs...>										t_row;// Add bias here ?
	typedef typename tuple::repeat<t_row, sizeof...(TOutputs)>::type	t_params;

	Neuron(void) = default;
	~Neuron(void) = default;

	inline void						set_initial_params(t_params const&& params)
	{
		m_parameters = params;
	};

	inline void						print_params(void) const
	{
		tuple::for_each([](auto &&value) {
			tuple::for_each([](auto &&value_in) {
				std::cout << "Value : " << value_in << std::endl;
			}, value);
		}, m_parameters);
	};

	inline std::tuple<TOutputs...>	forward(std::tuple<TInputs...> const &&input_values) const
	{
		// Simple matrix multiplication
		return (TType::output_fn(
					tuple::mult_tuple(
						std::move(input_values), std::move(m_parameters)
						, TType::merge_fn, TType::coef_fn
					)
				)
		);
	};

// Input ->		(2, 1)
// Params ->	(3, 3)
//				(5, 4)
// Output ->	(11, 10)
//
	inline std::tuple<TInputs...>	backward(std::tuple<TOutputs...> const&& output_values)
	{
		// const auto	result =
		(void)output_values;
		return (std::tuple<TInputs...>());
	};

private:

	t_params															m_parameters;
};

#endif
