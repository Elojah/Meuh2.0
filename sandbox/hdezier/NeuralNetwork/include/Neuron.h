/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Neuron.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 14:19:18 by leeios            #+#    #+#             */
/*   Updated: 2016/12/24 15:42:44 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEURON_H
# define NEURON_H

# include <iostream>
# include "tuple.h"


namespace	Functors
{
// Basics operators
	struct	Add
	{
		template<typename T, typename U>
		inline const T	operator()(const T &lhs, const U &rhs) const
		{
			return (lhs + rhs);
		};
		template<typename T>
		inline const T	operator()(const T &val) const
		{
			return (val);
		};
	};
	struct	Mult
	{
		template<typename T, typename U>
		inline const T	operator()(const T &lhs, const U &rhs) const
		{
			return (lhs * rhs);
		};
		template<typename T>
		inline const T	operator()(const T &val) const
		{
			return (val);
		};
	};
};

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
		constexpr static auto	coef_fn = Functors::Mult();
		constexpr static auto	merge_fn = Functors::Add();
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
	};

	inline std::tuple<TOutputs...>	forward(const std::tuple<TInputs...> &input_values) const
	{
		// Simple matrix multiplication
		return (tuple::fold2D(input_values, m_parameters, TType::coef_fn, TType::merge_fn));
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
