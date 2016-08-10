/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinearRegression2D.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 20:00:38 by hdezier           #+#    #+#             */
/*   Updated: 2016/08/10 21:48:30 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LinearRegression2D.h"

#include <iostream>

const float		LinearRegression2D::m_learning_rate = 0.0001;

void			LinearRegression2D::learn_from_data(void)
{
	float		tmp_theta_0 = 0;
	float		tmp_theta_1 = 0;
	for (const auto point : m_all_points)
	{
		const auto		tmp_estimation = current_estimation(point.at(0)) - point.at(1);
		tmp_theta_0 += tmp_estimation;
		tmp_theta_1 += tmp_estimation * point.at(0);
	}
	m_theta0 -= (m_learning_rate * tmp_theta_0) / m_all_points.size();
	m_theta1 -= (m_learning_rate * tmp_theta_1) / m_all_points.size();
	std::cout << "m_theta0: " << m_theta0 << std::endl;
	std::cout << "m_theta1: " << m_theta1 << std::endl;
}
