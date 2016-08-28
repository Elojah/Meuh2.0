/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ResourceShop.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 11:43:14 by leeios            #+#    #+#             */
/*   Updated: 2016/07/30 18:39:28 by leeios           ###   ########.fr       */
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

// Edge condition
bool					ResourceShop::_search_paths_empty_stack(
	const t_resource_stack &res_stack
	, const t_path &current_path
	, const t_resource_pack &res_pack
	, t_paths &result)
{
	std::cerr << "[SEARCH]" << "_search_paths_empty_stack" << std::endl;
	(void)res_stack;
	(void)res_pack;
	result.emplace_back(std::move(current_path));
	return (true);
}

// Add a prod to resources
bool					ResourceShop::_search_paths_prod(
	const t_resource_stack &res_stack
	, const t_path &current_path
	, const t_resource_pack &res_pack
	, t_paths &result)
{
	std::cerr << "[SEARCH]" << "_search_paths_prod" << std::endl;
	auto	next_res_pack = std::move(res_pack);
	map_helpers::_add_or_accumulate(next_res_pack, res_stack.top().name, res_stack.top().n);
	auto		next_res_stack = std::move(res_stack);
	next_res_stack.pop();
	return (_search_paths(next_res_stack, current_path, next_res_pack, result));
}

// Resource done -> unlock it
bool					ResourceShop::_search_paths_resource_done(
	const t_resource_stack &res_stack
	, const t_path &current_path
	, const t_resource_pack &res_pack
	, t_paths &result)
{
	std::cerr << "[SEARCH]" << "_search_paths_resource_done" << std::endl;
	_unlock_resource(res_stack.top().name);
	auto		next_res_stack = std::move(res_stack);
	next_res_stack.pop();
	return (_search_paths(next_res_stack, current_path, res_pack, result));
}

// Need a resource -> effective search
bool					ResourceShop::_search_paths_need(
	const t_resource_stack &res_stack
	, const t_path &current_path
	, const t_resource_pack &res_pack
	, t_paths &result)
{
	std::cerr << "[SEARCH]" << "_search_paths_need" << std::endl;
	if (_is_lock_resource(res_stack.top().name) || res_stack.top().n == 0)
	{
		std::cerr << "[CANCELLED]" << std::endl;
		return (false);
	}
	_lock_resource(res_stack.top().name);

	uint32_t	initial_resource = 0;
	if (res_pack.find(res_stack.top().name) != res_pack.end())
		initial_resource = res_pack.at(res_stack.top().name);
	bool		achievable(false);
	const uint32_t	n_res_max_used = std::min(initial_resource, res_stack.top().n);
	const uint32_t	n_step = n_res_max_used < m_max_steps_res_used ? 1 : n_res_max_used / m_max_steps_res_used;
	for (uint32_t i = 0; i <= n_res_max_used; i += n_step) // Condition on overflow, this is bad i know...
	{
		if (i == res_stack.top().n)
		{
			auto		next_res_stack = std::move(res_stack);
			next_res_stack.pop();

			auto		next_res_pack = std::move(res_pack);
			if (i != 0)
				next_res_pack.at(res_stack.top().name) -= i;

			auto		next_current_path = std::move(current_path);
			next_current_path.emplace_back(std::make_pair(0, i)); // Result path add

			_unlock_resource(res_stack.top().name);
			std::cerr << "[SEARCH]" << "DONE|_search_paths_: by resource" << std::endl;
			return (_search_paths(next_res_stack, next_current_path, next_res_pack, result));
		}
		else
		{
			// DISPATCH Stack + Res
			auto		next_res_pack = res_pack;
			if (i != 0)
				next_res_pack.at(res_stack.top().name) -= i;

			auto		next_res_stack = res_stack;
			next_res_stack.top().n -= i;

			// Add node with comb 0 (default) && i res used
			auto		next_current_path = current_path;
			next_current_path.emplace_back(std::make_pair(0, i)); // Result path add

			std::cerr << "[test]" << "resource consumed:" << next_res_stack.top().name << " x" << i << std::endl;
			achievable =_search_paths_comb_only(
				next_res_stack
				, next_current_path
				, next_res_pack
				, result) || achievable;
			std::cerr << "[DONE|test]" << "resource consumed:" << next_res_stack.top().name << " x" << i << std::endl;
		}
	}
	_unlock_resource(res_stack.top().name);
	auto		next_res_stack = std::move(res_stack);
	next_res_stack.pop();
	std::cerr << "[SEARCH]" << "DONE|_search_paths_: " << achievable << std::endl;
	return (achievable && _search_paths(next_res_stack, current_path, res_pack, result));
}

bool					ResourceShop::_search_paths_comb_only(
	const t_resource_stack &res_stack
	, const t_path &current_path
	, const t_resource_pack &res_pack
	, t_paths &result)
{
	std::cerr << "[SEARCH]" << "_search_paths_comb_only" << std::endl;
	const auto	&combinations = _get_combinations(std::make_pair(res_stack.top().name, res_stack.top().n));
	if (combinations.empty())
		return (false);
	bool		res_achievable = false;
	uint32_t	i_comb = 0;
	for (const auto &comb : combinations)
	{
		if (comb.empty())
			continue ;
		auto	next_res_stack = res_stack;
		next_res_stack.top().trade = e_trade::DONE;

		auto	next_current_path = current_path;
		next_current_path.back().first = i_comb;

		for (const auto &task : comb)
		{
			const auto		&resources_need = m_tasks.at(task.first).get_need();
			const auto		&resources_product = m_tasks.at(task.first).get_product();
			for (uint32_t i = 0; i < task.second; ++i)
			{
				for (const auto &res : resources_product)
				{
					if (res.first == res_stack.top().name)
					{
						if (res.second > res_stack.top().n)
							next_res_stack.emplace(res.first, res.second - res_stack.top().n, e_trade::PRODUCT);
					}
					else
						next_res_stack.emplace(res, e_trade::PRODUCT);
				}
				for (const auto &res : resources_need)
					next_res_stack.emplace(res, e_trade::NEED);
			}
		}
		std::cerr << "[test]" << "combination:" << i_comb << std::endl;
		res_achievable = _search_paths(next_res_stack, next_current_path, res_pack, result)
							|| res_achievable;
		std::cerr << "[DONE|test]" << "combination:" << i_comb << std::endl;
		++i_comb;
	}
	_unlock_resource(res_stack.top().name);
	auto		next_res_stack = std::move(res_stack);
	next_res_stack.pop();
	std::cerr << "[SEARCH]" << "DONE|_search_paths_comb_only: " << res_achievable << std::endl;
	return (res_achievable && _search_paths(next_res_stack, current_path, res_pack, result));
}

bool					ResourceShop::_search_paths(
	const t_resource_stack &res_stack
	, const t_path &current_path
	, const t_resource_pack &res_pack
	, t_paths &result)
{
	if (res_stack.empty())
		return (_search_paths_empty_stack(res_stack, current_path, res_pack, result));
	switch (res_stack.top().trade)
	{
		case (e_trade::PRODUCT) :
			return (_search_paths_prod(res_stack, current_path, res_pack, result));
		case (e_trade::DONE) :
			return (_search_paths_resource_done(res_stack, current_path, res_pack, result));
		case (e_trade::NEED) :
			return (_search_paths_need(res_stack, current_path, res_pack, result));
	}
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
	std::cout << "Result =" << std::endl;
	while (!toprint.empty())
	{
		std::cout << toprint.top().name << " : " << toprint.top().n << std::endl;
		toprint.pop();
	}
}

void				ResourceShop::print_path(const t_path &path, const std::string &resource)
{
	t_resource_stack		res_stack;

	uint32_t	lcm = _get_resource_lcm_prod(resource);
	res_stack.emplace(resource, lcm, e_trade::NEED);
	std::cout << "\033[21m________[Path]________\033[0m" << resource << " / lcm: " << lcm << std::endl;
	for (const auto &node : path)
	{
		std::cerr << "NODE:" << node.first << "/" << node.second << std::endl;
		if (res_stack.empty())
		{
			std::cerr << "Node is lost !" << std::endl;
			return ;
		}
		std::cout << "Resources:\t" << res_stack.top().name << std::endl;
		const auto	current_place = res_stack.top();
		res_stack.pop();
		if (node.second >= current_place.n)
		{
			std::cout << "Consumed ONLY:\t" << node.second << std::endl;
			continue ;
		}
		const auto	&combs_n = m_combinations.at(current_place.name).second.at(current_place.n);
		if (combs_n.empty())
		{
			std::cout << "Previous task accomplished:\t" << std::endl;
			continue ;
		}
		const auto	&current_comb = m_combinations.at(current_place.name).second.at(current_place.n).at(node.first);
		if (current_comb.empty())
		{
			std::cerr << "Combination bad indexed" << std::endl;
			return ;
		}
		for (const auto &task : current_comb)
		{
			std::cout << "\tProcess task:\t" << task.first << " x" << task.second << std::endl;
			const auto		&resources_need = m_tasks.at(task.first).get_need();
			for (uint32_t i = 0; i < task.second; ++i)
			{
				for (const auto &res : resources_need)
					res_stack.emplace(res, e_trade::NEED);
			}
		}
	}
};
