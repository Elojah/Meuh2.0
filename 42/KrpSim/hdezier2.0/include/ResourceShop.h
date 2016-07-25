/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ResourceShop.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 11:43:03 by leeios            #+#    #+#             */
/*   Updated: 2016/07/25 15:29:42 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOURCE_SHOP_H
# define RESOURCE_SHOP_H

# include "task_type.h"
# include "resource_type.h"

class ResourceShop
{
public:
	ResourceShop(const t_tasks &tasks);
	~ResourceShop(void) = default;

	const t_path_mult		&get_paths(
		const t_path &current
		, const t_resource_number &resource
		, const t_resource_pack &res_pack);

	// // USE CAREFULLY !!!
	// const t_tasks_sorted		&get_tasks_order(const std::string &res) const;


private:

	const t_tasks			&m_tasks;
	t_task_comb_by_res		m_combinations;
	t_resource_paths		m_paths;

	struct						comb_rec_ctx
	{
		const t_tasks_sorted	&tasks;
		uint64_t				size;
		t_task_comb				&result;
	};

// Paths
	void					_set_paths_by_pack(
		const t_path &current
		, const t_resource_number &resource
		, const t_resource_pack &res_pack);
	bool					_search_paths(
		const t_path &current
		, const t_resource_number &resource
		, const t_resource_pack &res_pack);
	bool					_search_paths_comb_only(
		const t_path &current
		, const t_resource_number &resource
		, const t_resource_pack &res_pack);

	uint32_t					_get_resource_lcm_prod(const std::string &resource_name) const;

// Combinations
	const t_task_comb			&_get_combinations(const t_resource_number &resource);

	void						_set_sorted_tasks(const std::string &resource_name
		, t_tasks_sorted &tasks);
	void						_set_task_comb_by_n(const t_tasks_sorted &tasks
		, const uint32_t n, t_task_comb &result);
	void						_get_comb_rec(t_task_pack current_pack
		, uint32_t i, uint32_t n, const comb_rec_ctx &p);
};

#endif
