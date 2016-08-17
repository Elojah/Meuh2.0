/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Neuron.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 14:19:18 by leeios            #+#    #+#             */
/*   Updated: 2016/08/17 17:17:07 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEURON_H
# define NEURON_H

# include "tuple.h"

namespace	Functors
{
	struct	Add
	{
		template<typename T>
		inline static T	apply(const T &lhs, const T &rhs)
		{
			return (lhs + rhs);
		};
	};
	struct	Mult
	{
		template<typename T>
		inline static T	apply(const T &lhs, const T &rhs)
		{
			return (lhs * rhs);
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
		inline static TOutput		apply(const std::tuple<TInputs...> &input
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
	};
};

template<typename...Ts>
class	Neuron;
template<typename TType, typename...TInputs, typename...TOutputs>
class	Neuron<TType, std::tuple<TInputs...>, std::tuple<TOutputs...>>
{
public:
	Neuron(void) = default;
	~Neuron(void) = default;

	inline void						set_initial_params(const std::tuple<TInputs...> &params)
	{
		for (uint32_t i = 0; i < sizeof...(TOutputs); ++i)
			m_parameters[i] = params;
	};

	inline std::tuple<TOutputs...>	forward(const std::tuple<TInputs...> &input_values) const
	{
		std::tuple<TOutputs...>		result;
		tuple::for_each(result, [this, &input_values](auto &value, const std::size_t i)
		{
			value = TType::template apply<typename std::remove_reference<decltype(value)>::type, TInputs...>
				(input_values, m_parameters[i]);
		});
		return (result);
	};

private:

	typedef std::tuple<TInputs...>		t_parameter_col;

	t_parameter_col		m_parameters[sizeof...(TOutputs)];
};



#endif
