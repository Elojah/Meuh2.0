/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Combination.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 19:22:06 by leeios            #+#    #+#             */
/*   Updated: 2016/07/14 10:12:35 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Combination.h"

t_task_comb		Combination::get_all(const t_tasks_sorted &tasks, const uint32_t n)
{
	t_task_comb				result;
	const param_rec_comb	p{tasks, tasks.size(), result};
	t_task_pack				empty_task;

	for (uint32_t i = 0; i < p.size; ++i)
		_get_comb_rec(empty_task, i, n, p);
	return (result);
}

void			Combination::_get_comb_rec(
	t_task_pack current_pack
	, uint32_t i
	, uint32_t n
	, const param_rec_comb &p)
{
	map_options::_add_or_accumulate(current_pack, p.tasks.at(i).first, (uint32_t)1);
	if (n <= p.tasks.at(i).second)
		p.result.push_back(current_pack);
	else
	{
		n -= p.tasks.at(i).second;
		for (; i < p.size; ++i)
			_get_comb_rec(current_pack, i, n, p);
	}
}
