/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_type.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 07:26:17 by leeios            #+#    #+#             */
/*   Updated: 2016/07/22 15:39:31 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TASK_TYPE_H
# define TASK_TYPE_H

# include <string>
# include <vector>
# include <queue>
# include <unordered_map>


class Task;

// Usuals
typedef std::unordered_map<std::string, Task>			t_tasks;
typedef std::vector<std::string>						t_tasks_name;
typedef std::unordered_map<std::string, uint32_t>		t_task_pack;
// Sort for combinations
typedef std::pair<std::string, uint32_t>				t_task_number;
typedef std::vector<t_task_number>						t_tasks_sorted;
// Combinations
typedef std::vector<t_task_pack>								t_task_comb;
typedef std::unordered_map<uint32_t, t_task_comb>				t_task_comb_by_n;
typedef std::pair<t_tasks_sorted, t_task_comb_by_n>				t_task_comb_with_sort;
typedef std::unordered_map<std::string, t_task_comb_with_sort>	t_task_comb_by_res;

namespace map_options
{
	template<typename TFirst, typename TSecond>
	inline bool	_add_or_accumulate(std::unordered_map<TFirst, TSecond> &dest
						, const TFirst &to_emplace_first
						, TSecond to_emplace_second)
	{
		auto	n_current(dest.find(to_emplace_first));
		if (n_current == dest.end())
		{
			dest.emplace(to_emplace_first, to_emplace_second);
			return (false);
		}
		else
		{
			n_current->second += to_emplace_second;
			return (true);
		}
	};
};

#endif
