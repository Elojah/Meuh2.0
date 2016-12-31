/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 14:17:28 by leeios            #+#    #+#             */
/*   Updated: 2016/12/30 17:19:19 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "libmem.h"

void					init_list(t_list *list)
{
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}

t_list_token			*new_list_token(void *data, t_list_token *next)
{
	t_list_token	*result;

	result = (t_list_token *)malloc(sizeof(t_list_token));
	if (result == NULL)
		return (result);
	result->data = data;
	result->next = next;
	return (result);
}

void					append(t_list *list, void *data)
{
	if (list->head == NULL)
	{
		list->head = new_list_token(data, NULL);
		list->tail = list->head;
	}
	else
	{
		list->tail->next = new_list_token(data, NULL);
		list->tail = list->tail->next;
	}
	++list->size;
}

void					free_list(t_list *list)
{
	t_list_token		*tmp;

	while (list->head != NULL)
	{
		if (list->head->data != NULL)
			ft_free(list->head->data);
		tmp = list->head;
		list->head = tmp->next;
		ft_free(tmp);
	}
}

void					print_list(t_list *list)
{
	t_list_token		*tmp;

	tmp = list->head;
	while (tmp != NULL)
	{
		printf(" %s", tmp->data);
		if (tmp != list->tail)
			printf(",");
		tmp = list->head->next;
	}
}
