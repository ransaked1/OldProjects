/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grila.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsandu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 20:47:01 by tsandu            #+#    #+#             */
/*   Updated: 2016/07/17 20:47:03 by tsandu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sudoku.h"

int	check_grila(char **tab, int n)
{
	int i;
	int j;

	i = 0;
	if (n == 10)
	{
		while (++i <= 9)
		{
			j = 0;
			while (tab[i][j])
			{
				if ((tab[i][j] < 48 || tab[i][j] > 57) && tab[i][j] != 46)
					return (0);
				j++;
			}
			if (j != 9)
				return (0);
		}
		return (1);
	}
	else
		return (0);
}
