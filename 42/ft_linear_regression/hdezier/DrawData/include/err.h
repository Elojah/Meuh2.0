/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 18:37:22 by hdezier           #+#    #+#             */
/*   Updated: 2016/08/27 20:40:18 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_H
# define ERR_H

enum class	e_err
{
	NO_ERR,
	BAD_ARG_NUMBER,
	BAD_FORMAT_CSV_INT,
	BAD_CSV_INT_NUMBER,
	SDL_WINDOW,
};

#endif
