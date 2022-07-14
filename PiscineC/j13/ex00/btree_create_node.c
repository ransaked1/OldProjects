/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 14:04:57 by dbraghis          #+#    #+#             */
/*   Updated: 2016/07/22 19:45:31 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

t_btree		*btree_create_node(void *item)
{
	t_btree		*copac;

	copac = (t_btree *)malloc(sizeof(t_btree));
	copac->item = item;
	copac->left = NULL;
	copac->right = NULL;
	return (copac);
}
