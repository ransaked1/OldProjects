/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 11:55:20 by dbraghis          #+#    #+#             */
/*   Updated: 2016/07/21 20:33:40 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list		*link(t_list *list, void *data)
{
	t_list		*head;

	head = malloc(sizeof(t_list));
	if (head)
	{
		head->data = data;
		head->next = list;
	}
	return (head);
}

t_list		*ft_list_push_params(int j, char **c)
{
	t_list		*head;
	int			i;

	i = 2;
	if (j == 1)
		return (NULL);
	head = ft_create_elem(c[1]);
	while (i < j)
	{
		head = link(head, c[i]);
		i++;
	}
	return (head);
}
