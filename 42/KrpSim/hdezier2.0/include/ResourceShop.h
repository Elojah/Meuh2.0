/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ResourceShop.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 11:43:03 by leeios            #+#    #+#             */
/*   Updated: 2016/07/14 11:54:14 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOURCE_SHOP_H
# define RESOURCE_SHOP_H

# include "task_type.h"

class ResourceShop
{
public:
	~ResourceShop(void) = default;

	static const t_task_comb		&get_n_resources(const std::string &resource
		, const uint32_t n, const t_tasks_sorted &tasks);
private:
	ResourceShop(void);

	static t_task_comb_by_res		m_cache;
};

#endif
