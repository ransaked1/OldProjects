/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 13:40:04 by dbraghis          #+#    #+#             */
/*   Updated: 2016/07/20 18:17:06 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_clear(t_list **begin_list)
{
	t_list		*head;
	t_list		*tmp;

	head = *begin_list;
	tmp = NULL;
	while (head)
	{
		if (head->next)
			tmp = head->next;
		else
			tmp = NULL;
		free(head);
		head = tmp;
	}
}
