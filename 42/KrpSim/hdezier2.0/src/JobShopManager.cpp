/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JobShopManager.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 02:43:06 by leeios            #+#    #+#             */
/*   Updated: 2016/06/13 09:07:05 by leeios           ###   ########.fr       */
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
				std::forward_as_tuple(std::numeric_limits<uint64_t>::max()));
	}
	if (resources_to_max.find(TIME_WORD) == resources_to_max.cend())
		return (_optimize_production(resources_to_max));
	else
		return (_optimize_time(resources_to_max));
}

e_err	JobShopManager::_optimize_production(const t_resource_pack &resources_to_max) const
{
	t_tasks_name		candidate_tasks;

	for (const auto t : m_tasks)
	{
		for (const auto res_need : resources_to_max)
		{
			if (t.second.get_need(res_need.first) != 0)
				candidate_tasks.emplace_back(t.first);
		}
	}
	return (e_err::TODO);
}

e_err	JobShopManager::_optimize_time(const t_resource_pack &resources_to_max) const
{
	t_tasks_name		candidate_tasks;
	double				max_ratio(0.0);
	std::string			max_task;

	for (const auto t : m_tasks)
	{
		for (const auto res_need : resources_to_max)
		{
			if (t.second.get_product(res_need.first) != 0)
			{
				auto	task_ratio = t.second.get_prod_ratio(max_ratio, resources_to_max);
				if (task_ratio > max_ratio)
				{
					max_ratio = task_ratio;
					max_task = t.first;
				}

			}
		}
	}
	return (e_err::TODO);
}
