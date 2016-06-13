/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Task.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 01:11:16 by leeios            #+#    #+#             */
/*   Updated: 2016/06/13 06:48:48 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Task.h"
#include <iostream>

Task::Task(const t_resource_pack_token &needs
	, const t_resource_pack_token &products, uint64_t time)
	: m_time(time)
{
	for (const auto n : needs)
	{
		if (m_needs.find(std::get<0>(n)) == m_needs.cend())
			m_needs.emplace(std::get<0>(n), std::get<1>(n));
		else
			m_needs.at(std::get<0>(n)) += std::get<1>(n);
	}
	for (const auto p : products)
	{
		if (m_products.find(std::get<0>(p)) == m_products.cend())
			m_products.emplace(std::get<0>(p), std::get<1>(p));
		else
			m_products.at(std::get<0>(p)) += std::get<1>(p);
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
