/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ResourceShop.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 11:43:14 by leeios            #+#    #+#             */
/*   Updated: 2016/07/25 16:50:53 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ResourceShop.h"
#include "Task.h"
#include <algorithm>

ResourceShop::ResourceShop(const t_tasks &tasks)
	: m_tasks(tasks)
{
	;
}

bool		ResourceShop::get_paths(
	const t_resource_stack		&res_stack
	, const t_resource_pack &res_pack)
{
	auto		paths_by_res = m_paths.emplace(
		std::piecewise_construct
		, std::forward_as_tuple(res_stack.top().first)
		, std::forward_as_tuple());
	auto		paths_by_pack = paths_by_res.first->second.emplace(
		std::piecewise_construct
		, std::forward_as_tuple(res_pack)
		, std::forward_as_tuple());
	if (paths_by_pack.second == false)
		_search_paths(res_stack, res_pack);
	return (true);
	// return (m_paths.at(resource.first).at(ResourcePack(res_pack)));
}

uint32_t			ResourceShop::_get_resource_lcm_prod(const std::string &resource_name) const
{
	const auto	&sub_tasks = m_combinations.at(resource_name).first;
	uint32_t		lcm = sub_tasks.at(0).second;
	for (const auto &task : sub_tasks)
		lcm = numeric_helper::ft_lcm(lcm, task.second);
	return (lcm);
}

bool					ResourceShop::_search_paths(
	const t_resource_stack		&res_stack
	, const t_resource_pack &res_pack)
{
	uint32_t	initial_resource = 0;
	if (res_pack.find(res_stack.top().first) != res_pack.end())
		initial_resource = res_pack.at(res_stack.top().first);
	for (uint32_t i = 0; i <= initial_resource; ++i)
	{
		if (i == initial_resource)
		{
			// TODO: Resource complete
		}
		else
		{
			// DISPATCH Stack + Res
			t_resource_pack		next_res_pack = res_pack;
			next_res_pack.at(res_stack.top().first) -= i;
			t_resource_stack	next_res_stack = res_stack;
			next_res_stack.pop();
			auto				last_resource = res_stack.top();
			last_resource.second -= i;
			next_res_stack.emplace(std::move(last_resource));

			_search_paths_comb_only(
				next_res_stack
				, next_res_pack);
		}
	}
	return (false);
}

bool					ResourceShop::_search_paths_comb_only(
	const t_resource_stack &res_stack
	, const t_resource_pack &res_pack)
{
	const auto	&combinations = _get_combinations(res_stack.top());
	for (const auto &comb : combinations)
	{
		for (const auto &task : comb)
		{
			t_resource_stack	next_stack = res_stack;
			const auto		&resources_need = m_tasks.at(task.first).get_need();
			for (uint32_t i = 0; i < task.second; ++i)
			{
				m_tasks.at(task.first).lock();
				for (const auto &res : resources_need)
					next_stack.emplace(res);
				m_tasks.at(task.first).unlock();
			}
		}
		// Unstack and return and resolve and get_paths
	}
	return (false);
}

const t_task_comb		&ResourceShop::_get_combinations(const t_resource_number &resource)
{
	auto		task_comb_by_res = m_combinations.emplace(
		std::piecewise_construct
		, std::forward_as_tuple(resource.first)
		, std::forward_as_tuple()).first;

	if (task_comb_by_res->second.first.empty())
		_set_sorted_tasks(resource.first, task_comb_by_res->second.first);
	auto		&task_comb_by_n = task_comb_by_res->second.second;
	auto		task_comb = task_comb_by_n.emplace(
		std::piecewise_construct
		, std::forward_as_tuple(resource.second)
		, std::forward_as_tuple());
	if (task_comb.second == true)
	{
		_set_task_comb_by_n(task_comb_by_res->second.first, resource.second
			, task_comb.first->second);
	}
	return (m_combinations.at(resource.first).second.at(resource.second));
}

// // USE CAREFULLY
// const t_tasks_sorted	&ResourceShop::get_tasks_order(const std::string &res) const
// {
// 	// MAY THROW AN UNCAUGHT EXCEPTION
// 	return (m_combinations.at(res).first);
// }

void					ResourceShop::_set_sorted_tasks(const std::string &resource_name
	, t_tasks_sorted &tasks_sorted)
{
	for (const auto &task : m_tasks)
	{
		const auto	prod = task.second.get_product(resource_name);
		const auto	need = task.second.get_need(resource_name);

		if (prod > need)
			tasks_sorted.emplace_back(task.first, prod);
	}
	std::sort(tasks_sorted.begin(), tasks_sorted.end()
		, [](const t_task_number &lhs, const t_task_number &rhs)->bool
		{
			return (lhs.second > rhs.second);
		});
}

void				ResourceShop::_set_task_comb_by_n(const t_tasks_sorted &tasks
	, const uint32_t n, t_task_comb &result)
{
	if (n == 0)
		return ;
	const comb_rec_ctx	p{tasks, tasks.size(), result};
	t_task_pack				empty_task;

	for (uint32_t i = 0; i < p.size; ++i)
		_get_comb_rec(empty_task, i, n, p);
}

void				ResourceShop::_get_comb_rec(t_task_pack current_pack
	, uint32_t i, uint32_t n, const comb_rec_ctx &p)
{
	map_helpers::_add_or_accumulate(current_pack, p.tasks.at(i).first, (uint32_t)1);
	if (n <= p.tasks.at(i).second)
		p.result.emplace_back(std::move(current_pack));
	else
	{
		n -= p.tasks.at(i).second;
		for (; i < p.size; ++i)
			_get_comb_rec(current_pack, i, n, p);
	}
}
