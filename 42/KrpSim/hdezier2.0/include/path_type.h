/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_type.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 18:30:28 by leeios            #+#    #+#             */
/*   Updated: 2016/07/25 22:20:52 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_TYPE_H
# define PATH_TYPE_H

# include <unordered_map>
# include <vector>

// Paths
typedef uint32_t												t_index_comb;
typedef uint32_t												t_n_resources_used;
typedef std::pair<t_index_comb, t_n_resources_used>				t_path_node;
typedef std::vector<t_path_node>								t_path;
typedef std::vector<t_path>										t_paths;

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
