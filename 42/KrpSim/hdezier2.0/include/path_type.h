/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_type.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 16:43:49 by leeios            #+#    #+#             */
/*   Updated: 2016/07/23 11:37:27 by leeios           ###   ########.fr       */
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
typedef std::vector<t_node>										t_path;
typedef std::vector<t_path>										t_path_mult;
// Starting task name
typedef std::unordered_map<std::string, t_path_mult>			t_path_origin_mult;
// Resource name
typedef std::unordered_map<std::string, t_path_origin_mult>		t_path_resource;

#endif
