/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resource_type.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 04:23:04 by leeios            #+#    #+#             */
/*   Updated: 2016/06/14 16:56:21 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOURCE_TYPE_H
# define RESOURCE_TYPE_H

# include <string>
# include <vector>
# include <unordered_map>

typedef std::vector<std::string>						t_resources_name;
typedef std::pair<std::string, uint64_t>				t_resource_number;
typedef std::vector<t_resource_number>					t_resource_pack_token;
typedef std::unordered_map<std::string, uint64_t>		t_resource_pack;

#endif
