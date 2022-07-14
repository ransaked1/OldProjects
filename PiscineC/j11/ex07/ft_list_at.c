/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 14:02:01 by dbraghis          #+#    #+#             */
/*   Updated: 2016/07/20 14:32:58 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list		*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list			*head;
	unsigned int	i;

	i = 0;
	head = begin_list;
	while (i < nbr)
	{
		if (!head)
			return (NULL);
		head = head->next;
		i++;
	}
	return (head);
}
