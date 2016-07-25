/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resource_type.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 04:23:04 by leeios            #+#    #+#             */
/*   Updated: 2016/07/25 20:21:10 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOURCE_TYPE_H
# define RESOURCE_TYPE_H

# include <string>
# include <vector>
# include <unordered_map>
# include <stack>

typedef std::vector<std::string>						t_resources_name;
typedef std::pair<std::string, uint32_t>				t_resource_number;
typedef std::vector<t_resource_number>					t_resource_pack_token;
typedef std::unordered_map<std::string, uint32_t>		t_resource_pack;

typedef std::stack<t_resource_number>					t_resource_stack;

struct ResourcePack
{
	inline ResourcePack(const t_resource_pack &res_pack) : data(res_pack) {};
	inline ResourcePack(t_resource_pack &&res_pack) : data(res_pack) {};
	~ResourcePack(void) = default;

	inline bool		operator==(const ResourcePack &rhs) const
	{
		return (data == rhs.data);
	};

	const t_resource_pack			&data;
};

struct		ResourcePackHash
{
	inline std::size_t		operator()(const ResourcePack &res_pack) const
	{
		std::size_t			result(0);
		for (const auto &res : res_pack.data)
		{
			result = (result)
				^ (std::hash<std::string>()(res.first))
				^ (std::hash<uint32_t>()(res.second));
		}
		return (result);
	};
};

# include "path_type.h"

typedef std::unordered_map<ResourcePack, t_paths, ResourcePackHash>		t_paths_by_pack;
typedef std::unordered_map<std::string, t_paths_by_pack>				t_resource_paths;

#endif
