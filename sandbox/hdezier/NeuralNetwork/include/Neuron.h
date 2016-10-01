/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Neuron.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 14:19:18 by leeios            #+#    #+#             */
/*   Updated: 2016/10/02 01:41:37 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEURON_H
# define NEURON_H

# include "tuple.h"

namespace	Functors
{
// Basics operators
	struct	Add
	{
		template<typename T, typename U>
		inline T	operator()(const T &lhs, const U &rhs)
		{
			return (lhs + rhs);
		};
		// template<typename T>
		// inline T	operator()(const T &val)
		// {
		// 	return (val);
		// };
	};
	struct	Mult
	{
		template<typename T, typename U>
		inline T	operator()(const T &lhs, const U &rhs)
		{
			return (lhs * rhs);
		};
		// template<typename T>
		// inline T	operator()(const T &val)
		// {
		// 	return (val);
		// };
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
// General type with 2 functors
	template<typename TInputFunctor, typename TOutputFunctor>
	struct	Parametrable
	{
		template<typename TOutput, typename...TInputs>
		inline static TOutput		compute_forward(const std::tuple<TInputs...> &input
			, const std::tuple<TInputs...> &parameters)
		{
			TOutput		result(0);

			tuple::for_each_both(input, parameters,
				[&result](const auto &value_input, const auto &value_param, const std::size_t i)
			{
				(void)i;
				result = TOutputFunctor(result
					, TOutput(TInputFunctor(value_input, value_param)));
			});
			return (result);
		};
		// template<typename TInput, typename...TOutput>
		// inline static TInput		compute_error(
		// 	const std::tuple<TOutput...> &error_delta
		// 	, )
		// {
		// 	;
		// };
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
		tuple::for_each(m_parameters, [&](auto &value, const auto &key) { (void)key;
			value = tuple::map(params, [&](const auto &value_j) {return (value_j);});
		});
	};

	inline std::tuple<TOutputs...>	forward(const std::tuple<TInputs...> &input_values) const
	{
		// Simple matrix multiplication
		tuple::for_each(input_values, [](const auto &elem, const auto &key){(void)key;std::cerr << elem.get() << "  --  ";});std::cerr << std::endl;
		return (tuple::fold2D(input_values, m_parameters, Functors::Mult(), Functors::Add()));
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
