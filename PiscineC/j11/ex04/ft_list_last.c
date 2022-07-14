/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 10:21:40 by dbraghis          #+#    #+#             */
/*   Updated: 2016/07/20 17:52:24 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list		*ft_list_last(t_list *begin_list)
{
	t_list		*head;

	head = begin_list;
	if (head)
	{
		while (head->next)
			head = head->next;
		return (head);
	}
	return (NULL);
}
