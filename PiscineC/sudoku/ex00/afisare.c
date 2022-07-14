/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afisare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsandu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 20:31:54 by tsandu            #+#    #+#             */
/*   Updated: 2016/07/17 20:31:56 by tsandu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sudoku.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

void	afisare(char **tab)
{
	int i;
	int j;

	i = 1;
	while (i <= 9)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			ft_putchar(tab[i][j]);
			if (j != 8)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
