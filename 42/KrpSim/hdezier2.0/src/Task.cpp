/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Task.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 01:11:16 by leeios            #+#    #+#             */
/*   Updated: 2016/07/23 13:37:48 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Task.h"
#include "ResourceShop.h"

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

uint32_t	Task::get_need(const std::string &resource) const
{
	if (m_needs.find(resource) == m_needs.end())
		return (0);
	return (m_needs.at(resource));
}

uint32_t			Task::get_product(const std::string &resource) const
{
	if (m_products.find(resource) == m_products.end())
		return (0);
	return (m_products.at(resource));
}

bool				Task::_consume_res(t_resource_pack &resources) const
{
	for (const auto &res_consumed : m_needs)
	{
		bool	consumed(false);
		for (auto &res : resources)
		{
			if (res_consumed.first == res.first
				&& res.second > res_consumed.second)
			{
				consumed = true;
				res.second -= res_consumed.second;
				break ;
			}
		}
		if (consumed == false)
			return (false);
	}
	return (true);
}

bool				Task::get_achievable_paths(
	const task_state &state
	, ResourceShop &resource_shop
	, t_path_mult &result
	, const t_tasks &tasks) const
{
	// Lock checking/setting
	if (m_lock_investing == true)
	{
		std::cout << "Cancelled loop" << std::endl;
		return (false);
	}
	m_lock_investing = true;

	// Check each resource. last one has last_requirement at true
	for (const auto &res_need : m_needs)
	{
		// Resources available test
		uint32_t	n_res_available = 0;
		if (state.res_available.find(res_need.first) != state.res_available.end())
			n_res_available = state.res_available.at(res_need.first);
		bool	res_achievable(false);
		for (uint32_t i_res_used = 0; i_res_used <= n_res_available && i_res_used <= res_need.second; ++i_res_used)
		{
			std::cout << res_need.first << " used " << i_res_used << " initials" << std::endl;
			if (i_res_used == res_need.second)
			{
				// New "leaf"
				task_state		next_state(state);

				next_state.res_available.at(res_need.first) -= i_res_used;
				next_state.current_path.push_back(std::make_pair(0, i_res_used));
				res_achievable = true;
				std::cout << "Add leaf" << std::endl;
				if (next_state.task_todo.empty())
				{
					std::cout << "Add final path" << std::endl;
					result.emplace_back(std::move(next_state.current_path));
				}
			}
			else
			{
				const auto		&tasks_comb = resource_shop.get_n_resources(res_need.first, res_need.second - i_res_used);
				if (tasks_comb.empty())
					continue ;
				// Complete with task combinations. ex:11222/3311/...
				uint32_t	i_comb(0);
				bool		combinations_achievable(false);
				for (const auto &comb_task : tasks_comb)
				{
					// New "node"
					task_state		next_state(state);

					next_state.current_path.push_back(std::make_pair(i_comb, i_res_used));
					std::cout << "Add combination" << std::endl;
					bool	comb_achievable(true);
					for (const auto &task : comb_task)
						next_state.task_todo.emplace(task);
					combinations_achievable = combinations_achievable || comb_achievable;
					++i_comb;
				}
				res_achievable = res_achievable || combinations_achievable;
			}
		}
		if (!res_achievable)
		{
			return (false);
			std::cout << "Resource IMPOSSIBLE to get:" << res_need.first << std::endl;
		}
		std::cout << "Resource OK:" << res_need.first << std::endl;
	}
	m_lock_investing = false;
	return (true);
}

void			Task::print_path(t_path &path, ResourceShop &resource_shop, const t_tasks &tasks) const
{
	if (path.empty())
	{
		std::cout << "End path" << std::endl;
		return ;
	}
	for (const auto &res : m_needs)
	{
		std::cout << res.second << 'x' << res.first << ':' << std::endl;
// Queue behavior, change with i !!!!
		const auto	node(path.front());
		path.erase(path.begin());
		const auto	&combs = resource_shop.get_n_resources(res.first, res.second - node.second);
		std::cout << "Node:" << node.first << " - res used:" << node.second << std::endl;
		if (combs.empty() || node.second >= res.second)
		{
			std::cout << node.second << " initials resources used" << std::endl;
			continue ;
		}
		if (node.first >= combs.size())
		{
			std::cout << "Overflow on node..." << std::endl;
			continue ;
		}
		const auto	&next_paths = combs.at(node.first);
		std::cout << node.second << " initials resources used" << std::endl;
		for (const auto &task : next_paths)
		{
			for (uint32_t i = 0; i < task.second; ++i)
			{
				std::cout << '[' << task.first << ']' << std::endl;
				tasks.at(task.first).print_path(path, resource_shop, tasks);
			}
		}
	}
}
