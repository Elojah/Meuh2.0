/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Task.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 01:11:21 by leeios            #+#    #+#             */
/*   Updated: 2016/06/14 19:10:58 by leeios           ###   ########.fr       */
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
	t_tasks_pack_ratio			get_prod_ratio(const t_resource_pack &resources_to_max
								, const t_resource_pack &resources_init
								, const std::string &task_name) const;

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
	t_tasks_link		m_sub_tasks;

	uint64_t			_n_executable(const t_resource_pack &resources_init) const;
	uint64_t			_calc_ratio_according_prod(uint64_t current_prod, const t_resource_pack &resources_to_max) const;
};

#endif
