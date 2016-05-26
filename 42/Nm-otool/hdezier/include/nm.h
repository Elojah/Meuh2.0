/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 16:15:40 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/26 17:16:35 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_H
# define NM_H

# include <stdio.h>

typedef enum	e_err
{
				NONE = 0,
				ERR_MMAP,
				ERR_ARG_NUMBER,
				ERR_FILE_OPEN,
				ERR_FILE_STAT,
				ERR_ARCHITECTURE_NOT_FOUND,
				E_ERR
}				t_err;

t_err		nm(char *file);


#endif
