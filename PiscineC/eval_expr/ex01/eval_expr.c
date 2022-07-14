/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 14:40:55 by dbraghis          #+#    #+#             */
/*   Updated: 2016/07/24 15:00:49 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unixtd.h>
#include "eval_expr.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		str_len(char *str)
{
	int		len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

int		*num_tab(char *str)
{
	int		i;
	int		l;
	int		*tab;
	char	*c;

	i = 0;
	l = str_len(str);
	tab = (int *)malloc(sizeof(int) * l);
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && <= '9')
		{
			j = 0;
			while (str[i] >= '0' && str[i] <= 9)
			{
				c[j] = str[i];
				j++;
				i++;
			}
			tab[k] = ft_atoi(c);
			k++;
		}

