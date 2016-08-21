/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Neuron.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 14:19:18 by leeios            #+#    #+#             */
/*   Updated: 2016/08/21 13:42:17 by leeios           ###   ########.fr       */
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
		template<typename T>
		inline T	operator()(const T &lhs, const T &rhs)
		{
			return (lhs + rhs);
		};
	};
	struct	Mult
	{
		template<typename T>
		inline T	operator()(const T &lhs, const T &rhs)
		{
			return (lhs * rhs);
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
// General type with 2 functors
	template<typename TInputFunctor, typename TOutputFunctor>
	struct	Parametrable
	{
		template<typename TOutput, typename...TInputs>
		inline static TOutput		compute_forward(const std::tuple<TInputs...> &input
			, const std::tuple<TInputs...> &parameters)
		{
			TOutput		result(0);

			tuple::for_each_both_const(input, parameters,
				[&result](const auto &value_input, const auto &value_param, const std::size_t i)
			{
				(void)i;
				result = TOutputFunctor::apply(result
					, TOutput(TInputFunctor::apply(value_input, value_param)));
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
		for (uint32_t i = 0; i < sizeof...(TOutputs); ++i)
			m_parameters.at(i) = params;
	};

	inline std::tuple<TOutputs...>	forward(const std::tuple<TInputs...> &input_values) const
	{
		// Simple matrix multiplication
		std::tuple<TOutputs...>		result;
		tuple::for_each(result, [this, &input_values](auto &value, const std::size_t i)
		{
			value = TType::template compute_forward<typename std::remove_reference<decltype(value)>::type, TInputs...>
				(input_values, m_parameters.at(i));
		});
		return (result);
	};

	inline std::tuple<TInputs...>	backward(const std::tuple<TOutputs...> &output_values)
	{
		(void)output_values;
		return (std::tuple<TInputs...>());
	};

private:
	typedef std::tuple<TInputs...>									t_parameter_col;// Add bias here ?

	template<typename T, std::size_t N>
	using	t_tuple_container = std::array<T, N>;

	typedef t_tuple_container<t_parameter_col, sizeof...(TOutputs)>	t_matrix_params;

	t_matrix_params													m_parameters;
};

#endif
