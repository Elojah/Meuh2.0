/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Task.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 01:11:16 by leeios            #+#    #+#             */
/*   Updated: 2016/07/16 13:09:30 by leeios           ###   ########.fr       */
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

bool				Task::get_achievable_paths(
	task_state &state
	, ResourceShop &resource_shop
	, t_path_mult &result
	, const t_tasks &tasks) const
{
	if (m_lock_investing == true)
	{
		std::cout << "Cancelled loop" << std::endl;
		return (false);
	}
	m_lock_investing = true;

	const uint32_t	need_size = m_needs.size();
	uint32_t		i_needs = 0;
	for (const auto &res_need : m_needs)
	{
		uint32_t	n_res_available = 0;
		bool		res_achievable(false);

		if (state.res_available.find(res_need.first) != state.res_available.end())
			n_res_available = state.res_available.at(res_need.first);
		// Fill with available resources
		for (uint32_t i = 0; i <= n_res_available && i <= res_need.second; ++i)
		{
			std::cout << res_need.first << " used " << i << " initials" << std::endl;
			const auto		&comb_tasks = resource_shop.get_n_resources(res_need.first, res_need.second - i);
			uint32_t		index_comb(0);

			if (i >= res_need.second)
			{
				res_achievable = true;
				state.current_path.push(std::make_pair(0, i));
				std::cout << "Add leaf" << std::endl;
				if (state.last_requirement && (i_needs == need_size - 1))
				{
					std::cerr << "Add final path:" << res_need.first << std::endl;
					result.push_back(state.current_path);
				}
				continue ;
			}
			// Complete with task combinations. ex:11222/3311/...
			for (const auto &comb_task : comb_tasks)
			{
				task_state		next_state(state);

				next_state.current_path.push(std::make_pair(index_comb, i));
				next_state.last_requirement = next_state.last_requirement && (i_needs == need_size - 1);
				if (next_state.res_available.find(res_need.first) != next_state.res_available.end())
					next_state.res_available.at(res_need.first) -= i;
				// Launch one combination ex:11222
				std::cout << "Test combination" << std::endl;
				bool	comb_achievable(true);
				for (const auto &task : comb_task)
				{
					std::cout << task.first << " x" << task.second << std::endl;
					// Launch one task. ex:1
					for (uint32_t i = 0; i < task.second && comb_achievable; ++i)
					{
						std::cout << "\tDepth +1:" << task.first << std::endl;
						comb_achievable = comb_achievable && tasks.at(task.first).get_achievable_paths(next_state, resource_shop, result, tasks);
						std::cout << "\tDepth -1:" << task.first << std::endl;
					}
				}
				res_achievable = res_achievable || comb_achievable;
				++index_comb;
			}
		}
		if (res_achievable == false)
		{
			std::cout << "Cancelled impossible" << std::endl;
			return (false);
		}
		std::cout << "Resource OK:" << res_need.first << std::endl;
		++i_needs;
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
		const auto	node(path.front());
		path.pop();
		const auto	&combs = resource_shop.get_n_resources(res.first, res.second - node.second);
		std::cout << "Node:" << node.first << " - res used:" << node.second << std::endl;
		if (combs.empty() || node.second >= res.second)
		{
			std::cout << node.second << " initials resources used" << std::endl;
			continue ;
		}
		if (node.first >= combs.size())
			continue ;
		const auto	&next_paths = combs.at(node.first);
		for (const auto &task : next_paths)
		{
			for (uint32_t i = 0; i < task.second; ++i)
			{
				std::cout << '[' << task.first << ']' << std::endl;
				tasks.at(task.first).print_path(path, resource_shop, tasks);
			}
		}
		path.pop();
	}
}
