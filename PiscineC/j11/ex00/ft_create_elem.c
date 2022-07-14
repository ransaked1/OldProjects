/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 16:37:56 by dbraghis          #+#    #+#             */
/*   Updated: 2016/07/20 14:39:08 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list		*ft_create_elem(void *data)
{
	t_list		*head;

	head = NULL;
	head = malloc(sizeof(t_list));
	if (head)
	{
		head->data = data;
		head->next = NULL;
	}
	return (head);
}
