/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_type.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 07:26:17 by leeios            #+#    #+#             */
/*   Updated: 2016/06/13 09:54:02 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TASK_TYPE_H
# define TASK_TYPE_H

# include <string>
# include <vector>
# include <unordered_map>

class Task;

typedef std::unordered_map<std::string, Task>			t_tasks;
typedef std::vector<std::string>						t_tasks_name;
typedef std::vector<std::tuple<std::string, uint64_t>>	t_task_exec;

#endif
