/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Task.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 01:11:16 by leeios            #+#    #+#             */
/*   Updated: 2016/07/14 20:06:29 by leeios           ###   ########.fr       */
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

void				Task::get_achievable_paths(
	const task_state &state
	, ResourceShop &resource_shop
	, t_path_mult &result
	, const task_context &task_ctx) const
{
	for (const auto &res_need : m_needs)
	{
		uint32_t	n_res_available = 0;
		if (state.res_available.find(res_need.first) != state.res_available.end())
			n_res_available = state.res_available.at(res_need.first);
		for (uint32_t i = 0; i < n_res_available; ++i)
		{
			const auto	&comb_resources = resource_shop.get_n_resources(res_need, i);
			for (const auto &comb : )
			task_state		next_state;

			next_state.res_available = state.res_available;
			next_state.current_path = state.current_path;

		}
	}
}
