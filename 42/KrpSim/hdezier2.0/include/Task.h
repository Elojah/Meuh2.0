/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Task.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 01:11:21 by leeios            #+#    #+#             */
/*   Updated: 2016/07/16 08:25:48 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TASK_H
# define TASK_H

# include "krpsim.h"
# include "resource_type.h"
# include "task_type.h"

# include <iostream>

class ResourceShop;

class Task
{
public:
	Task(const t_resource_pack_token &needs
		, const t_resource_pack_token &products, uint32_t time);
	~Task(void) = default;


	// struct					task_context
	// {
	// 	const std::string	&origin;
	// 	const t_tasks		&tasks;
	// };

	struct					task_state
	{
		task_state(void) = default;
		inline task_state(const task_state &state)
			: res_available(state.res_available)
			, current_path(state.current_path) {};
		t_resource_pack		res_available;
		t_path				current_path;
	};


	const t_resource_pack		&get_needs(void) const {return (m_needs);}
	uint32_t					get_need(const std::string &resource) const;
	uint32_t					get_product(const std::string &resource) const;

	bool						get_achievable_paths(
		const task_state &state
		, ResourceShop &resource_shop
		, t_path_mult &result
		, const t_tasks &tasks) const;

	// DEBUG
	inline void		print(void) const
	{
		// std::cerr << "\t_Needs_" << std::endl;
		// for (const auto &n : m_needs)
		// 	std::cerr << "\t\t" << n.first << ":" << (unsigned int)n.second << std::endl;
		// std::cerr << "\t_Products_" << std::endl;
		// for (const auto &n : m_products)
		// 	std::cerr << "\t\t" << n.first << ":" << (unsigned int)n.second << std::endl;
		// std::cerr << "\tTime:" << (unsigned int)m_time << std::endl;
		// std::cerr << "\tSubstasks:" << std::endl;
		// for (const auto &sub_task : m_sub_tasks)
		// 	std::cerr << ":" << sub_task.first << std::endl;
	};

private:
	t_resource_pack		m_needs;
	t_resource_pack		m_products;
	uint32_t			m_time;

	mutable bool		m_lock_investing;
};

#endif
