/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JobShopManager.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 02:43:12 by leeios            #+#    #+#             */
/*   Updated: 2016/06/06 05:32:20 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JOB_SHOP_MANAGER
# define JOB_SHOP_MANAGER

# include "krpsim.h"
# include "resource_type.h"

class JobShopManager
{
public:
	JobShopManager(void) = default;
	~JobShopManager(void) = default;
	e_err	set_initial_resources(const std::string &resource_name, uint64_t n);
	e_err	add_task(const std::string &task_name
		, const std::tuple<e_err, t_resource_pack> &needs
		, const std::tuple<e_err, t_resource_pack> &products
		, uint64_t time);
};

#endif
