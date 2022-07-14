/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 12:48:51 by dbraghis          #+#    #+#             */
/*   Updated: 2016/07/20 18:25:13 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_list_push_back(t_list **begin_list, void *data)
{
	t_list		*head;

	head = *begin_list;
	if (head)
	{
		while (head->next)
			head = head->next;
		head->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}
