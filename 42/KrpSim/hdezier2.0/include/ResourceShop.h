/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ResourceShop.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 11:43:03 by leeios            #+#    #+#             */
/*   Updated: 2016/07/16 08:13:47 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOURCE_SHOP_H
# define RESOURCE_SHOP_H

# include "task_type.h"

class ResourceShop
{
public:
	ResourceShop(const t_tasks &tasks);
	~ResourceShop(void) = default;

	const t_task_comb		&get_n_resources(const std::string &resource
		, const uint32_t n);
	// USE CAREFULLY !!!
	const t_tasks_sorted	&get_tasks_order(const std::string &res) const;

private:

	const t_tasks			&m_tasks;
	t_task_comb_by_res		m_cache;

	struct						param_rec_comb
	{
		const t_tasks_sorted	&tasks;
		uint64_t				size;
		t_task_comb				&result;
	};

	void						_set_sorted_tasks(const std::string &resource
		, t_tasks_sorted &tasks);
	void						_set_task_comb_by_n(const t_tasks_sorted &tasks
		, const uint32_t n, t_task_comb &result);
	void						_get_comb_rec(t_task_pack current_pack
		, uint32_t i, uint32_t n, const param_rec_comb &p);
};

#endif
