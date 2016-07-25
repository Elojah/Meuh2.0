/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ResourceShop.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 11:43:14 by leeios            #+#    #+#             */
/*   Updated: 2016/07/25 11:53:57 by leeios           ###   ########.fr       */
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

const t_path_mult		&ResourceShop::get_paths(const std::string &resource_name
	, const t_resource_pack &res_pack)
{
	auto		paths_by_res = m_paths.emplace(
		std::piecewise_construct
		, std::forward_as_tuple(resource_name)
		, std::forward_as_tuple());
	auto		paths_by_pack = paths_by_res.first->second.emplace(
		std::piecewise_construct
		, std::forward_as_tuple(res_pack)
		, std::forward_as_tuple());
	if (paths_by_pack.second == false)
		_set_paths_by_pack(resource_name, res_pack, paths_by_pack.first->second);
	return (m_paths.at(resource_name).at(ResourcePack(res_pack)));
}

uint32_t			ResourceShop::_get_resource_lcm_prod(const std::string &resource_name)
{
	const auto	&sub_tasks = m_combinations.at(resource_name).first;
	uint32_t		lcm = sub_tasks.at(0).second;
	for (const auto &task : sub_tasks)
		lcm = numeric_helper::ft_lcm(lcm, task.second);
	return (lcm);
}

void					ResourceShop::_set_paths_by_pack(const std::string &resource_name
	, const t_resource_pack &res_pack, t_path_mult &result)
{
	const uint32_t	res_lcm_prod = _get_resource_lcm_prod(resource_name);
	_search_paths(resource_name, res_lcm_prod, res_pack, result);
}

bool					ResourceShop::_search_paths(const std::string &resource_name
	, const uint32_t n, const t_resource_pack &res_pack, t_path_mult &result)
{
	uint32_t	initial_resource(0);
	if (res_pack.find(resource_name) != res_pack.end())
		initial_resource = res_pack.at(resource_name);
	for (uint32_t i = 0; i <= initial_resource; ++i)
	{
		if (i == initial_resource)
		{
			// TODO: Resource complete
		}
		else
		{
			t_resource_pack		next_res_pack(res_pack);
			_search_paths_comb_only(resource_name, n - i, res_pack, result);
		}
	}
	return (false);
}

bool					ResourceShop::_search_paths_comb_only(const std::string &resource_name
	, const uint32_t n, const t_resource_pack &res_pack, t_path_mult &result)
{

	for (const auto	)
	return (false);
}

const t_task_comb		&ResourceShop::get_combinations(const std::string &resource_name
	, const uint32_t n)
{
	auto		task_comb_by_res = m_combinations.emplace(
		std::piecewise_construct
		, std::forward_as_tuple(resource_name)
		, std::forward_as_tuple()).first;

	if (task_comb_by_res->second.first.empty())
		_set_sorted_tasks(resource_name, task_comb_by_res->second.first);
	auto		&task_comb_by_n = task_comb_by_res->second.second;
	auto		task_comb = task_comb_by_n.emplace(
		std::piecewise_construct
		, std::forward_as_tuple(n)
		, std::forward_as_tuple());
	if (task_comb.second == true)
	{
		_set_task_comb_by_n(task_comb_by_res->second.first, n
			, task_comb.first->second);
	}
	return (m_combinations.at(resource_name).second.at(n));
}

// USE CAREFULLY
const t_tasks_sorted	&ResourceShop::get_tasks_order(const std::string &res) const
{
	// MAY THROW AN UNCAUGHT EXCEPTION
	return (m_combinations.at(res).first);
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
