/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JobShopManager.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 02:43:06 by leeios            #+#    #+#             */
/*   Updated: 2016/06/06 06:06:29 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "JobShopManager.h"
#include <tuple>
#include <iostream>

e_err	JobShopManager::set_initial_resources(const std::string &resource_name, uint64_t n)
{
	std::cout << "Set initial resources [" << resource_name << "] at " << (unsigned int)n << std::endl;
	return (e_err::NONE);
}


e_err	JobShopManager::add_task(const std::string &task_name
	, const std::tuple<e_err, t_resource_pack> &needs
	, const std::tuple<e_err, t_resource_pack> &products
	, uint64_t time)
{
	std::cout << "Create task [" << task_name << "]" << std::endl;
	if (std::get<0>(needs) != e_err::NONE || std::get<0>(products) != e_err::NONE)
		return (e_err::RESOURCE_DEFINITION);

	std::cout << "Needs:" << std::endl;
	for (const auto n : std::get<1>(needs))
		std::cout << std::get<0>(n) << ":" << (unsigned int)std::get<1>(n) << std::endl;
	std::cout << "Products:" << std::endl;
	for (const auto n : std::get<1>(products))
		std::cout << std::get<0>(n) << ":" << (unsigned int)std::get<1>(n) << std::endl;
	std::cout << "In cycles:" << (unsigned int)time << std::endl;
	return (e_err::NONE);
}
