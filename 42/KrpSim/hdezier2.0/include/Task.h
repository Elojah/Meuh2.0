/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Task.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 01:11:21 by leeios            #+#    #+#             */
/*   Updated: 2016/06/17 18:47:41 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TASK_H
# define TASK_H

# include "krpsim.h"
# include "resource_type.h"
# include "task_type.h"

# include <iostream>

class Task
{
public:
	Task(const t_resource_pack_token &needs
		, const t_resource_pack_token &products, uint64_t time);
	~Task(void) = default;

	uint64_t					get_need(const std::string &resource) const;
	uint64_t					get_product(const std::string &resource) const;
	t_resource_pack				get_product(uint64_t n) const;
	t_task_pack					get_task_path(
								const std::string &task_name
								, uint64_t n_coef) const;

	void						set_sub_tasks(const t_tasks &all_tasks, const std::string &task_name);

	// DEBUG
	inline void		print(void) const
	{
		std::cerr << "\t_Needs_" << std::endl;
		for (const auto &n : m_needs)
			std::cerr << "\t\t" << n.first << ":" << (unsigned int)n.second << std::endl;
		std::cerr << "\t_Products_" << std::endl;
		for (const auto &n : m_products)
			std::cerr << "\t\t" << n.first << ":" << (unsigned int)n.second << std::endl;
		std::cerr << "\tTime:" << (unsigned int)m_time << std::endl;
		std::cerr << "\tSubstasks:" << std::endl;
		for (const auto &sub_task : m_sub_tasks)
			std::cerr << ":" << sub_task.first << std::endl;
	};

private:
	t_resource_pack		m_needs;
	t_resource_pack		m_products;
	uint64_t			m_time;
	t_tasks_link_by_res	m_sub_tasks;
	uint64_t			_n_executable(const t_resource_pack &resources_init) const;
	uint64_t			_calc_ratio_according_prod(uint64_t current_prod, const t_resource_pack &resources_to_max) const;

	inline static bool	_add_or_accumulate(std::unordered_map<std::string, uint64_t> &dest
						, const std::string &to_emplace_first
						, uint64_t to_emplace_second)
	{
		auto	n_current(dest.find(to_emplace_first));
		if (n_current == dest.end())
		{
			dest.emplace(to_emplace_first, to_emplace_second);
			return (false);
		}
		else
		{
			n_current->second += to_emplace_second;
			return (true);
		}
	}
};

#endif
