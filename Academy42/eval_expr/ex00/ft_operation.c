/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 16:44:58 by dbraghis          #+#    #+#             */
/*   Updated: 2016/07/24 14:09:46 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "eval_expr.h"

int		ft_atoi(char str)
{
	int		i;
	int		nbr;

	i = 0;
	nbr = 0;
	if (str >= 48 && str <= 57)
	{
		nbr = nbr * 10 + (int)str - '0';
	}
	return (nbr);
}

char	*ft_nbuc(char *str, char y, char *nbuc2)
{
	int		i;
	int		j;
	int		stop;

i = 0;
j = 0;
stop = 0;
	while (str[i] != '\0')
{
	if (str[i] >= 48 && str[i] <= 57 && stop == 0)
	{
		i = i + 5;
		nbuc2[j] = y;
		stop = 1;
		j++;
	}
	else if (str[i] != 40 || str[i] != 41)
	{
		nbuc2[j] = str[i];
		j++;
	}
	i++;
}
	return (nbuc2);
}

char	*ft_putnbr(char *str, int x)
{
	char	*nbuc2;
	char	y;

	y = x + '0';
	nbuc2 = (char *)malloc(sizeof(char) * str_len(str) - 5);
	if (str_len(str) == 5 || str_len(str) == 7)
	{
		*nbuc2 = y;
		return (nbuc2);
	}
	nbuc2 = ft_nbuc(str, y, nbuc2);
	return (nbuc2);
}
