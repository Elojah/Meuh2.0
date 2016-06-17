/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JobShopManager.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 02:43:06 by leeios            #+#    #+#             */
/*   Updated: 2016/06/17 19:07:06 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "JobShopManager.h"
#include <iostream>
#include <limits>
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

e_err	JobShopManager::optimize(const t_resources_name &to_opt)
{
	t_resource_pack		resources_to_max;

	for (const auto &s : to_opt)
		resources_to_max.emplace(s, 1);

	for (auto &t : m_tasks)
		t.second.set_sub_tasks(m_tasks, t.first);

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

	std::cout << "Start optimization..." << std::endl;

	for (const auto &t : m_tasks)
	{
		std::cout << "\tProduction task tested:" << t.first << std::endl;
		for (const auto res_need : resources_to_max)
		{
			std::cout << "\t\tLookin resource:" << res_need.first << std::endl;
			auto	n_coef(t.second.get_product(res_need.first));
			if (n_coef > 0)
			{
				std::cout << "\t\t\tStart depth search..." << std::endl;
				auto	task_path = t.second.get_task_path(t.first, n_coef);
				for (const auto &t : task_path)
					std::cerr << t.first << "\tx " << t.second << std::endl;
			}
		}
	}

	return (e_err::DEBUG);
}
