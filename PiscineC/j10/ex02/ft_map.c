/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 13:11:32 by dbraghis          #+#    #+#             */
/*   Updated: 2016/07/19 21:54:14 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f) (int))
{
	int		*intg;
	int		i;

	i = 0;
	intg = (int *)malloc(sizeof(int) * length);
	while (i < length)
	{
		intg[i] = f(tab[i]);
		i++;
	}
	return (intg);
}
