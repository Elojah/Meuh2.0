/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Task.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 01:11:16 by leeios            #+#    #+#             */
/*   Updated: 2016/06/10 02:35:09 by leeios           ###   ########.fr       */
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
