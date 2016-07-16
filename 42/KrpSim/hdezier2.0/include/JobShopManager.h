/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JobShopManager.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 02:43:12 by leeios            #+#    #+#             */
/*   Updated: 2016/07/16 08:36:34 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JOB_SHOP_MANAGER
# define JOB_SHOP_MANAGER

# define TIME_WORD (const char *)"time"

# include "krpsim.h"
# include "resource_type.h"
# include "Task.h"
# include "task_type.h"

# include <iostream>

class ResourceShop;

class JobShopManager
{
public:
	JobShopManager(void);
	~JobShopManager(void) = default;

	e_err	set_initial_resources(const std::string &resource_name, uint32_t n);
	e_err	add_task(const std::string &task_name
		, const t_resource_pack_token &needs
		, const t_resource_pack_token &products
		, uint32_t time);

	e_err	optimize(const t_resources_name &to_opt);

	// DEBUG
	inline void	print_tasks(void) const
	{
		for (const auto &t : m_tasks)
		{
			std::cerr << t.first << "=" << std::endl;
			t.second.print();
		}
	};
private:

	t_resource_pack		m_resources;
	t_tasks				m_tasks;

	e_err	_optimize_production(const t_resource_pack &resource_to_max) const;
	e_err	_optimize_time(const t_resource_pack &resource_to_max
		, ResourceShop &resource_shop) const;
	void	_print_path_mult(const std::string &first_task_name, t_path_mult &path, ResourceShop &res_shop) const;

};

#endif
