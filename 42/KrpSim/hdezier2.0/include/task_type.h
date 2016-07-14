/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_type.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 07:26:17 by leeios            #+#    #+#             */
/*   Updated: 2016/07/13 21:46:14 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TASK_TYPE_H
# define TASK_TYPE_H

# include <string>
# include <vector>
# include <unordered_map>
# include <map>

class Task;

typedef std::unordered_map<std::string, Task>			t_tasks;
typedef std::unordered_map<std::string, const Task *>	t_tasks_link;
typedef std::unordered_map<std::string, t_tasks_link>	t_tasks_link_by_res;
typedef std::vector<std::string>						t_tasks_name;
typedef std::pair<std::string, uint64_t>				t_task_number;
typedef std::vector<t_task_number>						t_tasks_sorted;
typedef std::unordered_map<std::string, uint64_t>		t_task_pack;
typedef std::vector<t_task_pack>						t_task_comb;
typedef std::unordered_map<std::string, t_task_comb>	t_task_comb_by_res;

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
