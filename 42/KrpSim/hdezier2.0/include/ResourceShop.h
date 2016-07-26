/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ResourceShop.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 11:43:03 by leeios            #+#    #+#             */
/*   Updated: 2016/07/26 22:20:34 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOURCE_SHOP_H
# define RESOURCE_SHOP_H

# include "task_type.h"
# include "resource_type.h"

// DBG
# include <iostream>

class ResourceShop
{
public:
	ResourceShop(const t_tasks &tasks);
	~ResourceShop(void) = default;

	inline bool			search_max_resource(const std::string &resource_name
		, const t_resource_pack &res_pack, t_paths &result)
	{
		t_resource_stack	res_stack; // empty
		t_path				path; // empty

		res_stack.emplace(resource_name, _get_resource_lcm_prod(resource_name), NEED);
		return (_search_paths(res_stack, path, res_pack, result));
	};

static void				print_stack(const t_resource_stack &res_stack);
void					print_path(const t_path &path, const std::string &resource);

private:

	const t_tasks			&m_tasks;
	t_task_comb_by_res		m_combinations;
	t_resource_paths		m_paths;
	t_resource_lock			m_res_lock;

	struct						comb_rec_ctx
	{
		const t_tasks_sorted	&tasks;
		uint64_t				size;
		t_task_comb				&result;
	};

// Lock
	inline void			_lock_resource(const std::string &resource_name)
	{
		std::cerr << "[LOCK]" << "lock " << resource_name << std::endl;
		if (m_res_lock.find(resource_name) == m_res_lock.end())
			m_res_lock.emplace(resource_name, true);
		else
			m_res_lock.at(resource_name) = true;
	};
	inline void			_unlock_resource(const std::string &resource_name)
	{
		std::cerr << "[LOCK]" << "unlock " << resource_name << std::endl;
		if (m_res_lock.find(resource_name) == m_res_lock.end())
			m_res_lock.emplace(resource_name, false);
		else
			m_res_lock.at(resource_name) = false;
	};
	inline bool			_is_lock_resource(const std::string &resource_name)
	{
		std::cerr << "[LOCK]" << "check lock " << resource_name << std::endl;
		if (m_res_lock.find(resource_name) == m_res_lock.end())
			return (false);
		else
			return (m_res_lock.at(resource_name));
	};
// Paths
	bool					_search_paths(
		const t_resource_stack &res_stack
		, const t_path &current_path
		, const t_resource_pack &res_pack
		, t_paths &result);
	bool					_search_paths_comb_only(
		const t_resource_stack &res_stack
		, const t_path &current_path
		, const t_resource_pack &res_pack
		, t_paths &result);

	uint32_t					_get_resource_lcm_prod(const std::string &resource_name);

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
