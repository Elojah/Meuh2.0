/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ResourceShop.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 11:43:14 by leeios            #+#    #+#             */
/*   Updated: 2016/07/25 17:56:26 by leeios           ###   ########.fr       */
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

uint32_t			ResourceShop::_get_resource_lcm_prod(const std::string &resource_name)
{
	_get_combinations(std::make_pair(resource_name, 0));
	const auto		&sub_tasks = m_combinations.at(resource_name).first;
	if (sub_tasks.empty())
		return (0);
	uint32_t		lcm = sub_tasks.at(0).second;
	for (const auto &task : sub_tasks)
		lcm = numeric_helper::ft_lcm(lcm, task.second);
	return (lcm);
}

bool		ResourceShop::_get_paths(
	const t_resource_stack_pair &res_stacks
	, const t_resource_pack &res_pack)
{
	std::cerr << "_get_paths" << std::endl;
	// auto		paths_by_res = m_paths.emplace(
	// 	std::piecewise_construct
	// 	, std::forward_as_tuple(res_stacks.first.top().first)
	// 	, std::forward_as_tuple());
	// auto		paths_by_pack = paths_by_res.first->second.emplace(
	// 	std::piecewise_construct
	// 	, std::forward_as_tuple(res_pack)
	// 	, std::forward_as_tuple());
	// if (paths_by_pack.second == false)
		return (_search_paths(res_stacks, res_pack));
	// return (true);
	// return (m_paths.at(resource.first).at(ResourcePack(res_pack)));
}

bool					ResourceShop::_search_paths(
	const t_resource_stack_pair &res_stacks
	, const t_resource_pack &res_pack)
{
	std::cerr << "_search_paths" << std::endl;
	uint32_t	initial_resource = 0;
	if (res_pack.find(res_stacks.first.top().first) != res_pack.end())
		initial_resource = res_pack.at(res_stacks.first.top().first);
	bool		achievable(false);
	for (uint32_t i = 0; i <= initial_resource && i <= res_stacks.first.top().second; ++i)
	{
		if (i == res_stacks.first.top().second)
		{
			auto		next_res_stacks = res_stacks;
			next_res_stacks.second.emplace(std::move(next_res_stacks.first.top()));
			next_res_stacks.first.pop();
			if (next_res_stacks.first.empty())
			{
				print_stack(next_res_stacks.second);
				return (true);
			}
		}
		else
		{
			// DISPATCH Stack + Res
			auto		next_res_pack = res_pack;
			if (i != 0)
				next_res_pack.at(res_stacks.first.top().first) -= i;
			auto		next_res_stacks = res_stacks;
			next_res_stacks.second.emplace(std::move(next_res_stacks.first.top()));
			next_res_stacks.first.pop();
			auto				last_resource = res_stacks.first.top();
			last_resource.second -= i;
			next_res_stacks.first.emplace(std::move(last_resource));

			achievable = achievable || _search_paths_comb_only(
				next_res_stacks
				, next_res_pack);
		}
	}
	return (achievable);
}

bool					ResourceShop::_search_paths_comb_only(
	const t_resource_stack_pair &res_stacks
	, const t_resource_pack &res_pack)
{
	std::cerr << "_search_paths_comb_only" << std::endl;
	const auto	&combinations = _get_combinations(res_stacks.first.top());
	if (combinations.empty())
		return (false);
	bool		res_achievable = false;
	for (const auto &comb : combinations)
	{
		auto	next_res_stacks = res_stacks;
		next_res_stacks.second.emplace(std::move(next_res_stacks.first.top()));
		next_res_stacks.first.pop();
		for (const auto &task : comb)
		{
			const auto		&resources_need = m_tasks.at(task.first).get_need();
			for (uint32_t i = 0; i < task.second; ++i)
			{
				m_tasks.at(task.first).lock();
				for (const auto &res : resources_need)
					next_res_stacks.first.emplace(res);
				m_tasks.at(task.first).unlock();
			}
		}
		res_achievable = res_achievable || _get_paths(next_res_stacks, res_pack);
	}
	return (res_achievable);
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

void				ResourceShop::print_stack(const t_resource_stack &res_stack)
{
	t_resource_stack	toprint = res_stack;
	while (!toprint.empty())
	{
		std::cout << toprint.top().first << " : " << toprint.top().second << std::endl;
		toprint.pop();
	}
}
