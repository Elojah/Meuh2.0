/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Task.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 01:11:16 by leeios            #+#    #+#             */
/*   Updated: 2016/07/14 11:47:00 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Task.h"
#include "Combination.h"
#include <iostream>
#include <limits>
#include <algorithm>

Task::Task(const t_resource_pack_token &needs
	, const t_resource_pack_token &products, uint32_t time)
	: m_time(time)
	, m_lock_investing(false)
{
	if (m_time == 0)
		m_time = 1;
	for (const auto &n : needs)
		map_options::_add_or_accumulate(m_needs, n.first, n.second);
	for (const auto &p : products)
		map_options::_add_or_accumulate(m_products, p.first, p.second);
}

void		Task::set_sub_tasks(const t_tasks &all_tasks, const std::string &task_name)
{
	// Different ways to optimize here
	// We assume for this one n resources need < n task
	for (const auto &res_need : m_needs)
		m_sub_tasks.emplace(std::piecewise_construct
			, std::forward_as_tuple(res_need.first)
			, std::forward_as_tuple());
	for (const auto &task : all_tasks)
	{
		if (task.first == task_name)
			continue ;
		for (const auto &res_need : m_needs)
		{
			if (task.second.get_product(res_need.first) > 0)
				m_sub_tasks.at(res_need.first).emplace(task.first, &task.second);
		}
	}
}

void		Task::set_task_comb(void)
{
	for (const auto &res_need : m_needs)
	{
		const auto &sub_tasks = m_sub_tasks.find(res_need.first);
		if (sub_tasks == m_sub_tasks.cend() || sub_tasks->second.empty())
			continue ;
		t_tasks_sorted		sorted_task_by_res;
		for (const auto &task : sub_tasks->second)
		{
			sorted_task_by_res.emplace_back(task.first
				, task.second->get_product(res_need.first));
		}
		std::sort(sorted_task_by_res.begin(), sorted_task_by_res.end(),
			[](const t_task_number &lhs, const t_task_number &rhs) -> bool
			{
				return (lhs.second > rhs.second);
			});
		m_task_combs.emplace(res_need.first, Combination::get_all(sorted_task_by_res, res_need.second));
	}
}

uint32_t	Task::get_need(const std::string &resource) const
{
	if (m_needs.find(resource) == m_needs.cend())
		return (0);
	return (m_needs.at(resource));
}

uint32_t			Task::get_product(const std::string &resource) const
{
	if (m_products.find(resource) == m_products.cend())
		return (0);
	return (m_products.at(resource));
}
