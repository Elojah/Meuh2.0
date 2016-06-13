/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   krpsim.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 00:48:24 by leeios            #+#    #+#             */
/*   Updated: 2016/06/13 13:03:45 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KRPSIM_H
# define KRPSIM_H

# define PRINT_ERR(n) std::cerr << "[DBG]" << n << std::endl;

enum class e_err
{
	NONE = 0,
	BAD_ARG_NUMBER,
	OPEN_FAILED,
	RESOURCE_NAME_NOT_FOUND,
	TASK_DEFINITION_SYNTAX_NEED,
	TASK_DEFINITION_SYNTAX_PRODUCT,
	TASK_DEFINITION_SYNTAX_TIME,
	TASK_DUPLICAT,
	RESOURCE_DEFINITION,
	OPTIMIZE_NOT_DEFINED,
	OPTIMIZE_SYNTAX_ERR,
	DEBUG,
	TODO,
	E_ERR
};


#endif
