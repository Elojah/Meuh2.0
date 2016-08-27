/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradientDescent.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 21:10:10 by leeios            #+#    #+#             */
/*   Updated: 2016/08/15 01:18:06 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADIENT_DESCENT_H
# define GRADIENT_DESCENT_H

# include "type_set.h"
# include "tuple_helper.h"

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
		double		theta0;
		double		theta1;
	};
	struct			IterResult
	{
		LinearFunction	lf;
		double			least_square_error;
	};

	inline static IterResult	iter(
		const type_set::t_features_set<Ts...> &data_set
		, const LinearFunction &prev_fun
		, const double learning_rate)
	{
		(void)learning_rate;
		for (const auto &data_line : data_set)
		{
			const auto	&actual_output = std::get<std::tuple_size<decltype(data_set)>::value - 1>(data_set);
			for_each(data_set, [prev_fun](const auto &feature)
				{
					if (&feature == &actual_output)
						return ;
					std::cout << feature << std::endl;
				}
			);
		}
	};
private:
	GradientDescent(void);
	GradientDescent(const GradientDescent &copy);
	GradientDescent(GradientDescent &&copy);
	~GradientDescent(void);
};

#endif
