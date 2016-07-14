/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Combination.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 19:21:56 by leeios            #+#    #+#             */
/*   Updated: 2016/07/13 18:03:27 by leeios           ###   ########.fr       */
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

	struct	param_rec_comb
	{
		const t_tasks_sorted	&tasks;
		uint64_t				size;
		t_task_comb				&result;
	};

	static void				_get_comb_rec(
		t_task_pack current_pack
		, uint64_t i
		, uint64_t n
		, const param_rec_comb &p);

};

#endif
