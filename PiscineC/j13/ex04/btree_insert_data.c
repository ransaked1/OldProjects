/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 18:32:41 by dbraghis          #+#    #+#             */
/*   Updated: 2016/07/22 19:24:20 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
			int (*cmpf)(void *, void *))
{
	if (!*root)
	{
		*root = btree_create_node(item);
		return ;
	}
	if (cmpf((*root)->item, item) <= 0)
	{
		if (!(*root)->right)
		{
			(*root)->right = btree_create_node(item);
			return ;
		}
		btree_insert_data(&((*root)->right), item, cmpf);
	}
	else
	{
		if (!(*root)->item)
		{
			(*root)->left = btree_create_node(item);
			return ;
		}
		btree_insert_data(&((*root)->left), item, cmpf);
	}
}
