/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resource_type.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 04:23:04 by leeios            #+#    #+#             */
/*   Updated: 2016/06/13 06:47:29 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOURCE_TYPE_H
# define RESOURCE_TYPE_H

# include <string>
# include <vector>
# include <unordered_map>

typedef std::vector<std::string>						t_resources_name;
typedef std::tuple<std::string, uint64_t>				t_resource_number;
typedef std::vector<std::tuple<std::string, uint64_t>>	t_resource_pack_token;
typedef std::unordered_map<std::string, uint64_t>		t_resource_pack;

#endif
