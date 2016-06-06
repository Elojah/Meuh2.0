/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   krpsim.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 00:48:24 by leeios            #+#    #+#             */
/*   Updated: 2016/06/06 05:34:23 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KRPSIM_H
# define KRPSIM_H

# define PRINT_ERR(n) std::cerr << n << std::endl;

enum class e_err
{
	NONE = 0,
	BAD_ARG_NUMBER,
	OPEN_FAILED,
	RESOURCE_NAME_NOT_FOUND,
	TASK_DEFINITION_SYNTAX_NEED,
	TASK_DEFINITION_SYNTAX_PRODUCT,
	TASK_DEFINITION_SYNTAX_TIME,
	RESOURCE_DEFINITION,
	DEBUG,
	TODO,
	E_ERR
};

#endif