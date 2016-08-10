/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinearRegression2D.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 20:00:46 by hdezier           #+#    #+#             */
/*   Updated: 2016/08/10 21:42:34 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINEAR_REGRESSION_2D_H
# define LINEAR_REGRESSION_2D_H

# include "type_csv.h"
# include <vector>

class LinearRegression2D
{
public:
	inline LinearRegression2D(void)
	: m_theta0(0)
	, m_theta1(0)
	{}
	~LinearRegression2D(void) = default;

	void		learn_from_data(void);
	inline int	current_estimation(const int input) const {return (m_theta0 + (m_theta1 * input));};
	inline void	add_to_data(const type_csv::csv_params<2> &csv_params) {m_all_points.emplace_back(csv_params);};

private:

	static const float	m_learning_rate;

	float			m_theta0;
	float			m_theta1;

	typedef std::array<float, 2>			t_coordinates;
	typedef std::vector<t_coordinates>		t_graph;

	t_graph		m_all_points;
};

#endif
