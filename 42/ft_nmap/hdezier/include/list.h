/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 14:17:25 by leeios            #+#    #+#             */
/*   Updated: 2016/12/30 17:19:56 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct			s_list_token
{
	void				*data;
	struct s_list_token	*next;
}						t_list_token;

typedef struct			s_list
{
	t_list_token		*head;
	t_list_token		*tail;
	unsigned int		size;
}						t_list;

void					init_list(t_list *list);
void					append(t_list *list, void *data);
void					free_list(t_list *list);
void					print_list(t_list *list);

#endif
