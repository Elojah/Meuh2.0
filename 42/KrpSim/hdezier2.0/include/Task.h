/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Task.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 01:11:21 by leeios            #+#    #+#             */
/*   Updated: 2016/07/24 13:47:27 by leeios           ###   ########.fr       */
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


	uint32_t					get_need(const std::string &resource) const;
	uint32_t					get_product(const std::string &resource) const;
	inline void					lock(void) const {m_lock_investing = true;};
	inline void					unlock(void) const {m_lock_investing = false;};
	inline bool					isLock(void) const {return (m_lock_investing);};

private:
	t_resource_pack		m_needs;
	t_resource_pack		m_products;
	uint32_t			m_time;

	mutable bool		m_lock_investing;

};

#endif
