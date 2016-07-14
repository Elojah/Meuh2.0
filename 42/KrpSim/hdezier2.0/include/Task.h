/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Task.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 01:11:21 by leeios            #+#    #+#             */
/*   Updated: 2016/07/14 15:11:45 by leeios           ###   ########.fr       */
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
		, const t_resource_pack_token &products, uint32_t time);
	~Task(void) = default;

	uint32_t					get_need(const std::string &resource) const;
	uint32_t					get_product(const std::string &resource) const;

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

	// mutable bool		m_lock_investing;
};

#endif
