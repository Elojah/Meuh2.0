/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JobShopManager.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 02:43:12 by leeios            #+#    #+#             */
/*   Updated: 2016/06/13 06:52:16 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JOB_SHOP_MANAGER
# define JOB_SHOP_MANAGER

# include "krpsim.h"
# include "resource_type.h"
# include "Task.h"

# include <iostream>

class JobShopManager
{
public:
	JobShopManager(void);
	~JobShopManager(void) = default;
	e_err	set_initial_resources(const std::string &resource_name, uint64_t n);
	e_err	add_task(const std::string &task_name
		, const t_resource_pack_token &needs
		, const t_resource_pack_token &products
		, uint64_t time);

	// DEBUG
	inline void	print_tasks(void) const
	{
		for (const auto t : m_tasks)
		{
			std::cerr << t.first << "=" << std::endl;
			t.second.print();
		}
	};

	e_err	optimize(const t_resources_name &to_opt) const;

private:

	typedef std::unordered_map<std::string, Task>			t_tasks;
	typedef std::vector<std::string>						t_tasks_name;

	t_resource_pack		m_resources;
	t_tasks				m_tasks;
};

#endif
