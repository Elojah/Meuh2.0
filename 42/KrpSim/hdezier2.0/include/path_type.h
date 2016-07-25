/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_type.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 18:30:28 by leeios            #+#    #+#             */
/*   Updated: 2016/07/25 14:46:48 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_TYPE_H
# define PATH_TYPE_H

# include <unordered_map>
# include <queue>
# include <vector>

// Paths
// first = index of combination. second = n of resource used
typedef std::pair<uint32_t, uint32_t>							t_node;
typedef std::queue<t_node>										t_path;
typedef std::vector<t_path>										t_path_mult;

struct				path_stack
{
	t_path			current_path;
	t_path_mult		&valid_paths;
};

namespace numeric_helper
{
	template<typename T>
	T	ft_gcd(T a, T b)
	{
		for (;;)
		{
			if (a == 0) return b;
			b %= a;
			if (b == 0) return a;
			a %= b;
		}
	}
	template<typename T>
	T	ft_lcm(T a, T b)
	{
		T	tmp = ft_gcd<T>(a, b);
		return (tmp ? (a / tmp * b) : 0);
	}
};

#endif
