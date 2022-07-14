/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 14:18:50 by dbraghis          #+#    #+#             */
/*   Updated: 2016/07/20 17:39:15 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_reverse(t_list **begin_list)
{
	t_list		*head;
	t_list		*tmp;
	t_list		*tmp1;

	tmp = NULL;
	head = *begin_list;
	if (!head || !(head->next))
		return ;
	tmp = head->next;
	tmp1 = tmp->next;
	head->next = NULL;
	tmp->next = head;
	while (tmp1)
	{
		head = tmp;
		tmp = tmp1;
		tmp1 = tmp1->next;
		tmp->next = head;
	}
	*begin_list = tmp;
}
