/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_type.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 07:26:17 by leeios            #+#    #+#             */
/*   Updated: 2016/06/14 17:08:47 by leeios           ###   ########.fr       */
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
typedef std::vector<std::string>						t_tasks_name;
typedef std::pair<std::string, uint64_t>				t_task_number;
typedef std::vector<t_task_number>						t_tasks_pack;
typedef std::pair<double, t_tasks_pack>					t_tasks_pack_ratio;
typedef std::multimap<double, t_tasks_pack>				t_task_exec;

#endif
