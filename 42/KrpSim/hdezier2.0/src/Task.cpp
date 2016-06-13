/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Task.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 01:11:16 by leeios            #+#    #+#             */
/*   Updated: 2016/06/13 18:09:38 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Task.h"
#include <iostream>

Task::Task(const t_resource_pack_token &needs
	, const t_resource_pack_token &products, uint64_t time)
	: m_time(time)
{
	if (m_time == 0)
		m_time = 1;
	for (const auto &n : needs)
	{
		if (m_needs.find(std::get<0>(n)) == m_needs.cend())
			m_needs.emplace(std::get<0>(n), std::get<1>(n));
		else
			m_needs.at(std::get<0>(n)) += std::get<1>(n);
	}
	for (const auto &p : products)
	{
		if (m_products.find(std::get<0>(p)) == m_products.cend())
			m_products.emplace(std::get<0>(p), std::get<1>(p));
		else
			m_products.at(std::get<0>(p)) += std::get<1>(p);
	}
}

void		Task::set_sub_tasks(const t_tasks &all_tasks, const std::string &task_name)
{
	for (const auto &task : all_tasks)
	{
		for (const auto &res_need : m_needs)
		{
			if (task.first != task_name && task.second.get_product(res_need.first) > 0)
			{
				m_sub_tasks.emplace(std::piecewise_construct,
					std::forward_as_tuple(task.first),
					std::forward_as_tuple(&task.second));
				break ;
			}
		}
	}
}

uint64_t	Task::get_need(const std::string &resource) const
{
	if (m_needs.find(resource) == m_needs.cend())
		return (0);
	return (m_needs.at(resource));
}

uint64_t	Task::get_product(const std::string &resource) const
{
	if (m_products.find(resource) == m_products.cend())
		return (0);
	return (m_products.at(resource));
}

t_tasks_pack_ratio	Task::get_prod_ratio(const t_resource_pack &resources_to_max
	, const t_resource_pack &resources_init, const std::string &task_name) const
{
	auto					current_prod(_n_executable(resources_init));
	t_tasks_pack_ratio		result(t_tasks_pack_ratio{0, {}});

	(void)resources_to_max;
	if (current_prod > 0)
	{
		std::cout << "\t\t\t\tBasic production found:" << task_name << std::endl;
		std::get<0>(result) = (double)_calc_ratio_according_prod(current_prod, resources_to_max) / m_time;
		std::get<1>(result).emplace_back(t_task_number{task_name, current_prod});
		return (result);
	}
	for (const auto &sub_task : m_sub_tasks)
	{
		std::cout << "\t\t\t\tLookin for sub tasks:" << sub_task.first << std::endl;
		auto	task_result = sub_task.second->get_prod_ratio(m_needs, resources_init, sub_task.first);
		if (std::get<0>(task_result) == 0)
			continue ;
		std::get<0>(task_result) /= m_time;
		std::cout << "\t\t\t\t\tFound prod ratio:" << std::get<0>(task_result) << "\t" << task_name << std::endl;
		std::get<1>(result).insert(std::get<1>(result).end()
			, std::get<1>(task_result).begin(), std::get<1>(task_result).end());
		// return (task_result);
	}
	return (result);
}

uint64_t		Task::_n_executable(const t_resource_pack &resources_init) const
{
	uint64_t	result(std::numeric_limits<uint64_t>::max());

	for (const auto &res_need : m_needs)
	{
		for (const auto &res_available : resources_init)
		{
			if (res_need.first == res_available.first && res_need.second > 0)
			{
				uint64_t	n_prod(res_available.second / res_need.second);
				if (n_prod < result)
					result = n_prod;
				goto next_resource;
			}
		}
		return (0);
		next_resource:
		if (result == 0)
			return (0);
	}
	return (result);
}

uint64_t		Task::_calc_ratio_according_prod(uint64_t current_prod, const t_resource_pack &resources_to_max) const
{
	uint64_t	result(0);

	for (const auto &product : m_products)
	{
		for (const auto &res_to_max : resources_to_max)
		{
			if (product.first == res_to_max.first)
			{
				result += product.second * current_prod * res_to_max.second;
				break ;
			}
		}
	}
	return (result);
}
