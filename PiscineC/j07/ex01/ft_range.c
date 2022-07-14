/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 11:29:32 by dbraghis          #+#    #+#             */
/*   Updated: 2016/07/14 13:16:27 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*tab;
	int		i;
	int		j;

	i = 0;
	j = min;
	if (min >= max)
		tab = NULL;
	tab = (int*)malloc(sizeof(int) * (max - min));
	while (j < max)
	{
		tab[i] = min + i;
		i++;
		j++;
	}
	return (tab);
}
