/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JobShopManager.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 02:43:06 by leeios            #+#    #+#             */
/*   Updated: 2016/06/13 14:00:59 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "JobShopManager.h"
#include <iostream>
#include <limits>
#include <tuple>
#include <unordered_map>

/**
 * @brief JobShopManager constructor
 * @details IMPORTANT: unordered_map task -> float point error if there's no reserve(1)
 */
JobShopManager::JobShopManager(void)
{
	m_tasks.reserve(1);
}

e_err	JobShopManager::set_initial_resources(const std::string &resource_name, uint64_t n)
{
	if (m_resources.find(resource_name) == m_resources.cend())
		m_resources.emplace(resource_name, n);
	else
		m_resources.at(resource_name) += n;
	return (e_err::NONE);
}

e_err	JobShopManager::add_task(const std::string &task_name
	, const t_resource_pack_token &needs
	, const t_resource_pack_token &products
	, uint64_t time)
{
	if (m_tasks.find(task_name) != m_tasks.cend())
		return (e_err::TASK_DUPLICAT);
	m_tasks.emplace(std::piecewise_construct,
			std::forward_as_tuple(task_name),
			std::forward_as_tuple(needs, products, time));
	return (e_err::NONE);
}

e_err	JobShopManager::optimize(const t_resources_name &to_opt) const
{
	t_resource_pack		resources_to_max;

	for (const auto s : to_opt)
	{
		resources_to_max.emplace(std::piecewise_construct,
				std::forward_as_tuple(s),
				std::forward_as_tuple(1));
	}
	// for (auto task : m_tasks)
	// {
	// 	std::cerr << "Link sub_tasks to " << task.first << std::endl;
	// 	task.second.set_sub_tasks(m_tasks);
	// }

//	if (resources_to_max.find(TIME_WORD) == resources_to_max.cend())
//		return (_optimize_production(resources_to_max));
//	else
		return (_optimize_time(resources_to_max));
}

e_err	JobShopManager::_optimize_production(const t_resource_pack &resources_to_max) const
{
	(void)resources_to_max;
	return (e_err::TODO);
}

e_err	JobShopManager::_optimize_time(const t_resource_pack &resources_to_max) const
{
	t_tasks_name		candidate_tasks;
	t_task_exec			tasks_exec;

	std::cout << "Start optimization..." << std::endl;
	for (auto t : m_tasks)
	{
		std::cerr << "Link sub_tasks to " << t.first << std::endl;
		t.second.set_sub_tasks(m_tasks);
		t.second.print();
	}

	for (auto t : m_tasks)
	{
		std::cout << "\tProduction task tested:" << t.first << std::endl;
		for (const auto res_need : resources_to_max)
		{
			std::cout << "\t\tLookin resource:" << res_need.first << std::endl;
			if (t.second.get_product(res_need.first) != 0)
			{
				std::cout << "\t\t\tStart depth search..." << std::endl;
				tasks_exec.emplace(t.second.get_prod_ratio(resources_to_max, m_resources, t.first));
				break ;
			}
		}
	}
	for (const auto task_to_ex : tasks_exec)
	{
		std::cout << "Ratio:\t" << task_to_ex.first << std::endl;
		for (const auto tasks_n : task_to_ex.second)
			std::cout << std::get<0>(tasks_n) << "\t x" << std::get<1>(tasks_n) << std::endl;
	}
	return (e_err::DEBUG);
}
