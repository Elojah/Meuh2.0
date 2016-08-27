/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinearRegression2D.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 20:00:46 by hdezier           #+#    #+#             */
/*   Updated: 2016/08/13 21:05:52 by leeios           ###   ########.fr       */
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

	void			learn_from_data(void);
	void			_learn_from_data(void);
	inline double	current_estimation(const double input) const {return (m_theta0 + (m_theta1 * input));};
	inline void		add_to_data(const type_csv::csv_params<2> &csv_params) {m_all_points.emplace_back(csv_params);};

private:

	double			m_learning_rate;
	double			m_precision;

	double			m_theta0;
	double			m_theta1;
	double			m_current_epsilon;

	typedef std::array<double, 2>			t_coordinates;
	typedef std::vector<t_coordinates>		t_graph;

	t_graph		m_all_points;

};

#endif
