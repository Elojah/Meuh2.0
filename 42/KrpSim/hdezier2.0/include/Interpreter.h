/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interpreter.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 02:38:52 by leeios            #+#    #+#             */
/*   Updated: 2016/06/14 16:57:40 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERPRETER_H
# define INTERPRETER_H

# include "krpsim.h"
# include "resource_type.h"

# define COMMENT_DELIM '#'
# define FIRST_DELIM ':'
# define CURRENT_DELIM ':'
# define DIGITS "0123456789"
# define RES_SEPARATOR ';'
# define OPTIMIZE_WORD (const char *)"optimize"

template<class T>
class Interpreter
{
public:
	Interpreter(T &job_shop_manager);
	~Interpreter(void) = default;
	e_err	read_line(const std::string &line, const bool quickExit);

private:
	T		&m_job_shop_manager;
	e_err	_read_task_name(const std::string &line);
	e_err	_read_task_attributes(const std::string &resource_name
		, const std::string &line);
	const std::pair<e_err, t_resource_pack_token>	_str_to_resource(const std::string &s) const;
	const std::pair<e_err, t_resource_number>		_set_resource_number(const std::string &s) const;
	const std::pair<e_err, t_resources_name>		_read_resource_name(const std::string &s) const;
};

#endif
