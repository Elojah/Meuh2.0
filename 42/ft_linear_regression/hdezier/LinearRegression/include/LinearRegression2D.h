/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinearRegression2D.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 20:00:46 by hdezier           #+#    #+#             */
/*   Updated: 2016/08/28 19:08:02 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINEAR_REGRESSION_2D_H
# define LINEAR_REGRESSION_2D_H

# include "type_csv.h"
# include <vector>

class LinearRegression2D
{
public:

	typedef std::array<double, 2>			t_coordinates;
	typedef std::vector<t_coordinates>		t_graph;

	inline LinearRegression2D(void)
	: m_theta0(0)
	, m_theta1(0)
	{}
	~LinearRegression2D(void) = default;

	void						learn_from_data(void);
	double						_learn_from_data(void);
	inline double				current_estimation(const double input) const {return (m_theta0 + (m_theta1 * input));};
	inline void					add_to_data(const type_csv::csv_params<2> &csv_params) {m_all_points.emplace_back(csv_params);};
	inline const t_graph		&get_data_points(void) const {return (m_all_points);};
	inline const t_coordinates	get_function(void) const {return (t_coordinates{{m_theta0, m_theta1}});};

private:

	double			m_learning_rate;
	double			m_precision;

	double			m_theta0;
	double			m_theta1;
	double			m_current_epsilon;

	t_graph		m_all_points;

};

#endif
