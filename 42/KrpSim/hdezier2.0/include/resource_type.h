/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resource_type.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 04:23:04 by leeios            #+#    #+#             */
/*   Updated: 2016/07/27 13:26:28 by leeios           ###   ########.fr       */
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

enum class	e_trade
{
	NEED,
	PRODUCT,
	DONE
};

struct	resource_trade
{
	inline	resource_trade(const std::string &name_p, const uint32_t n_p, const e_trade trade_p)
	: name(name_p)
	, n(n_p)
	, trade(trade_p)
	{};
	inline	resource_trade(const t_resource_number &res_number, const e_trade trade_p)
	: name(res_number.first)
	, n(res_number.second)
	, trade(trade_p)
	{};
	const std::string	name;
	uint32_t			n;
	e_trade				trade;
};

typedef std::stack<resource_trade>					t_resource_stack;

typedef std::unordered_map<std::string, bool>			t_resource_lock;

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
