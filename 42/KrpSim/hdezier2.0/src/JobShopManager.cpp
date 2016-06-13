/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JobShopManager.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 02:43:06 by leeios            #+#    #+#             */
/*   Updated: 2016/06/13 06:52:17 by leeios           ###   ########.fr       */
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
	t_resource_pack		resource_needed;
	t_tasks_name		candidate_tasks;

	for (const auto s : to_opt)
	{
		resource_needed.emplace(std::piecewise_construct,
				std::forward_as_tuple(s),
				std::forward_as_tuple(std::numeric_limits<uint64_t>::max()));
	}
	for (const auto t : m_tasks)
	{
		for (const auto res_need : resource_needed)
		{
			if (t.second.get_need(res_need.first) != 0)
				candidate_tasks.push_back(t.first);
		}
	}
	return (e_err::TODO);
}
