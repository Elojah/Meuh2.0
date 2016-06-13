/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resource_type.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 04:23:04 by leeios            #+#    #+#             */
/*   Updated: 2016/06/13 10:45:05 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOURCE_TYPE_H
# define RESOURCE_TYPE_H

# include <string>
# include <vector>
# include <unordered_map>

typedef std::vector<std::string>						t_resources_name;
typedef std::tuple<std::string, uint64_t>				t_resource_number;
typedef std::vector<t_resource_number>					t_resource_pack_token;
typedef std::unordered_map<std::string, uint64_t>		t_resource_pack;

#endif
