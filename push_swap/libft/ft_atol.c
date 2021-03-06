/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 09:37:23 by dbraghis          #+#    #+#             */
/*   Updated: 2017/03/18 19:27:16 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(char *nb)
{
	int		i;
	int		neg;
	long	num;

	i = 0;
	neg = 1;
	num = 0;
	while (nb[i] == ' ' || nb[i] == '\t' || nb[i] == '\r' || nb[i] == '\v'
			|| nb[i] == '\f' || nb[i] == '\n')
		i++;
	while ((nb[i] != '\0' && nb[i] >= '0' && nb[i] <= '9') || nb[i] == '+' ||
			nb[i] == '-')
	{
		if (nb[i] == '-')
			neg = -1;
		if (nb[i] >= '0' && nb[i] <= '9')
			num = num * 10 + (nb[i] - '0');
		if (nb[i + 1] < '0' || nb[i + 1] > '9' || nb[i + 1] == '\0')
			return (num * neg);
		i++;
	}
	return (num);
}
