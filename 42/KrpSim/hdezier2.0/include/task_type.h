/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_type.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 07:26:17 by leeios            #+#    #+#             */
/*   Updated: 2016/06/17 18:39:47 by leeios           ###   ########.fr       */
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
typedef std::unordered_map<std::string, uint64_t>		t_task_pack;

#endif
