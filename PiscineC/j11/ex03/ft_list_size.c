/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 21:30:22 by dbraghis          #+#    #+#             */
/*   Updated: 2016/07/20 14:14:44 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	t_list		*head;
	int			i;

	i = 0;
	head = begin_list;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}
