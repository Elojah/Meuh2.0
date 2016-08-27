/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinearRegression2D.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 20:00:38 by hdezier           #+#    #+#             */
/*   Updated: 2016/08/27 18:41:46 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LinearRegression2D.h"

#include <iostream>

/**
 * IN -> Vector Data, t0 initial = 0, t1 initial = 0, precision
 * OUT -> t0, t1, n iterations, precision
 */

void			LinearRegression2D::learn_from_data(void)
{
	m_learning_rate = 0.0001;
	m_precision = 0.0001;
	m_current_epsilon = m_precision + 1;
	while (m_current_epsilon > m_precision || m_current_epsilon < -m_precision)
		_learn_from_data();
}

void			LinearRegression2D::_learn_from_data(void)
{
	double		tmp_theta_0 = 0;
	double		tmp_theta_1 = 0;
	double		tmp_epsilon = 0;

	for (const auto point : m_all_points)
	{
		const auto		point_epsilon = current_estimation(point.at(0)) - point.at(1);

		tmp_epsilon += point_epsilon;
		tmp_theta_0 += point_epsilon;
		tmp_theta_1 += point_epsilon * point.at(0);
	}
	m_current_epsilon = tmp_epsilon;
	m_theta0 -= (m_learning_rate * tmp_theta_0) / m_all_points.size();
	m_theta1 -= (m_learning_rate * tmp_theta_1) / m_all_points.size();
}
