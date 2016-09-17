/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradientDescent.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 21:10:10 by leeios            #+#    #+#             */
/*   Updated: 2016/08/15 20:12:27 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADIENT_DESCENT_H
# define GRADIENT_DESCENT_H

# include "type_set.h"
# include "type_helper.h"

# include <iostream>

/**
 * IN -> Vector Data, t0 initial = 0, t1 initial = 0, learning_rate
 * OUT -> t0, t1, precision
 */

template<typename T>
class	GradientDescent;

template<typename...Ts>
class	GradientDescent<type_set::t_features<Ts...>>
{
public:
	struct			LinearFunction
	{
		std::array<double, sizeof...(Ts)>	theta;
	};
	struct			IterResult
	{
		LinearFunction	lf;
		std::array<double, sizeof...(Ts)>	least_square_error;
	};
	inline static IterResult	iter(
		const type_set::t_features_set<Ts...> &data_set
		, const LinearFunction &prev_estimation
		, const double learning_rate)
	{
		(void)learning_rate;
		for (const auto &data_line : data_set)
		{
			const auto	&actual_output = std::get<std::tuple_size<decltype(data_set)>::value - 1>(data_set);
			for_each(data_set, [prev_estimation](const auto &feature)
				{
					if (&feature == &actual_output)
						return ;
					std::cout << feature << std::endl;
				}
			);
		}
	};

	// typedef type_helper::select_last<Ts...>			t_output_type;
	typedef typename std::tuple_element<sizeof...(Ts) - 1, Ts...>::type	t_output_type;
	typedef std::array<t_output_type, sizeof...(Ts)>					t_output;

	typedef typename type_helper::pop_back<Ts...>::type					t_features_type;

	inline static t_output		estimate(t_features_type &&features, const LinearFunction &lf)
	{
		std::tuple<Ts...>	param_adjust = {features, t_output_type(0)};
		return (estimate(param_adjust, lf));
	};

private:
	GradientDescent(void);
	GradientDescent(const GradientDescent &copy);
	GradientDescent(GradientDescent &&copy);
	~GradientDescent(void);
};

#endif
