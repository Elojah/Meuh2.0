/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 19:23:34 by leeios            #+#    #+#             */
/*   Updated: 2015/12/31 17:45:01 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"
#include "unistd.h"
#include "stdlib.h"

static void		print_error(t_error err)
{
	const char	*err_msgs[SIZE_ENUM_ERROR + 1];
	int			i;

	err_msgs[0] = "NO ERROR"; // NONE = 0,
	err_msgs[1] = "Usage: ./tetris [file_name...]";	// NO_ARGS,
	err_msgs[2] = "Error occured while reading file"; // READING_ERROR,
	err_msgs[3] = "Unknown char found"; // UNKNOWN_CHAR,
	err_msgs[4] = "Bad separation found between pieces"; // BAD_SEPARATION,
	err_msgs[5] = "No four bloc found in piece"; // NO_FOUR_IN_A_ROW,
	err_msgs[6] = "No disposition found"; // NO_DISPOSITION_FOUND,
	err_msgs[7] = "No disposition found for specific size"; // NO_DISPOSITION_FOUND_AT_SIZE,
	err_msgs[8] = "NO ERROR"; // SIZE_ENUM_ERROR

	if (err <= 0 || err >= SIZE_ENUM_ERROR)
		return ;
	i = 0;
	while (err_msgs[err][i] != '\0')
		++i;
	write(2, err_msgs[err], i);
	write(2, "\n", 1);
}

void		exit_with_error(t_error err_value)
{
	if (err_value == 0)
		return ;
	print_error(err_value);
	exit(2);
}
