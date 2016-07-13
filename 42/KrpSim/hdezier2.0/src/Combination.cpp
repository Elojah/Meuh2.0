/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Combination.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 19:22:06 by leeios            #+#    #+#             */
/*   Updated: 2016/07/13 16:39:21 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Combination.h"

t_task_comb		Combination::get_all(const t_tasks_sorted &tasks, const uint64_t n)
{
	t_task_comb		result;
	const uint64_t	size(tasks.size());

	for (uint64_t i = 0; i < size; ++i)
		_get_comb_start(i, tasks, n, result);
	return (result);
}

void			Combination::_get_comb_rec(, const t_tasks_sorted &tasks
	, uint64_t n, t_task_comb &result)
{
	const uint64_t	size(tasks.size());

	for (; start < size; ++start)
	{
		const uint64_t	ratio(_get_ratio(n, tasks.at(start).second));
		result.emplace_back(tasks.at(start).first, ratio);


	}
}

uint64_t	Combination::_get_ratio(uint64_t need, uint64_t prod)
{
	return ((need % prod) == 0 ? (need / prod) : (need / prod) + 1);
}
