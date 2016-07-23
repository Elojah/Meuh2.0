/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JobShopManager.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 02:43:06 by leeios            #+#    #+#             */
/*   Updated: 2016/07/22 15:37:31 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "JobShopManager.h"
#include "ResourceShop.h"
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

e_err	JobShopManager::set_initial_resources(const std::string &resource_name, uint32_t n)
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
	, uint32_t time)
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
	ResourceShop		resource_shop(m_tasks);

	for (const auto &s : to_opt)
		resources_to_max.emplace(s, 1);

//	if (resources_to_max.find(TIME_WORD) == resources_to_max.cend())
//		return (_optimize_production(resources_to_max));
//	else
	return (_optimize_time(resources_to_max, resource_shop));
}

e_err	JobShopManager::_optimize_production(const t_resource_pack &resources_to_max) const
{
	(void)resources_to_max;
	return (e_err::TODO);
}

e_err	JobShopManager::_optimize_time(const t_resource_pack &resources_to_max
	, ResourceShop &resource_shop) const
{
	t_tasks_name		candidate_tasks;

	std::cout << "_______Start optimization..." << std::endl;

	for (const auto &res : resources_to_max)
	{
		std::cout << "Examining resource:\033[34m" << res.first << "\033[0m..." << std::endl;
		for (const auto &task : m_tasks)
		{
			if (task.second.get_product(res.first) > task.second.get_need(res.first))
			{
				Task::task_state	state;
				t_path_mult			result;

				state.res_available = m_resources;
				bool possible = task.second.get_achievable_paths(state, resource_shop, result, m_tasks);
				if (possible == true)
				{
					std::cout << "\033[31mPath(s) found !\033[0m" << std::endl;
					for (auto &path : result)
					{
						std::cout << "______Path:_________" << std::endl;
						std::cout << '[' << task.first << ']' << std::endl;
						(void)path;
						task.second.print_path(path, resource_shop, m_tasks);
						std::cout << "_____________________" << std::endl;
					}
				}
			}
		}
	}

	return (e_err::TODO);
}
