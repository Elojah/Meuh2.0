/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Combination.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 19:21:56 by leeios            #+#    #+#             */
/*   Updated: 2016/07/13 16:14:53 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMBINATION_H
# define COMBINATION_H

# include "task_type.h"

class Combination
{
public:
	Combination(void) = default;
	~Combination(void) = default;

	static t_task_comb		get_all(const t_tasks_sorted &tasks, const uint64_t n);
private:
	static void				_get_comb_start(uint64_t start, const t_tasks_sorted &tasks
		, uint64_t n, t_task_comb &result);

	static uint64_t			_get_ratio(uint64_t need, uint64_t prod);

};

#endif
