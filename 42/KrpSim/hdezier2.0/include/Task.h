/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Task.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 01:11:21 by leeios            #+#    #+#             */
/*   Updated: 2016/07/23 13:39:17 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TASK_H
# define TASK_H

# include "krpsim.h"
# include "resource_type.h"
# include "task_type.h"
# include "path_type.h"

# include <iostream>
# include <stack>

class ResourceShop;

class Task
{
public:
	Task(const t_resource_pack_token &needs
		, const t_resource_pack_token &products, uint32_t time);
	~Task(void) = default;

	struct					task_state
	{
		inline task_state(void) = default;
		inline task_state(const task_state &state)
			: res_available(state.res_available)
			, current_path(state.current_path)
			, task_todo(state.task_todo) {};

		t_resource_pack				res_available;
		t_path						current_path;
		std::stack<t_task_number>	task_todo;
		std::string					previous_task;
	};

	uint32_t					get_need(const std::string &resource) const;
	uint32_t					get_product(const std::string &resource) const;

	bool						get_achievable_paths(
		const task_state &state
		, ResourceShop &resource_shop
		, t_path_mult &result
		, const t_tasks &tasks) const;

	void						print_path(t_path &path, ResourceShop &resource_shop, const t_tasks &tasks) const;

private:
	t_resource_pack		m_needs;
	t_resource_pack		m_products;
	uint32_t			m_time;

	mutable bool		m_lock_investing;

	bool				_consume_res(t_resource_pack &resources) const;
};

#endif
