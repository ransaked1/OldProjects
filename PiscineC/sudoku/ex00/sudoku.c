/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsandu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 20:32:10 by tsandu            #+#    #+#             */
/*   Updated: 2016/07/17 20:35:20 by tsandu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sudoku.h"

int	check_column(char **tab, char nb, int y)
{
	int	column;

	column = 1;
	while (column <= 9)
	{
		if (tab[column][y] == nb)
			return (0);
		column++;
	}
	return (1);
}

int	check_line(char **tab, char nb, int x)
{
	int row;

	row = 0;
	while (row < 9)
	{
		if (tab[x][row] == nb)
			return (0);
		row++;
	}
	return (1);
}

int	check_block(char **tab, int x, int y, char nb)
{
	int row;
	int column;

	row = -1;
	if (x <= 3)
		x = 1;
	else if (x <= 6)
		x = 4;
	else if (x <= 9)
		x = 7;
	y = y - (y % 3);
	while (++row < 3)
	{
		column = -1;
		while (++column < 3)
		{
			if (tab[x][y] == nb)
				return (0);
			y++;
		}
		y = y - 3;
		x++;
	}
	return (1);
}

int	sudoku(char **tab, int position)
{
	int		x;
	int		y;
	char	nb;

	nb = '0';
	x = position / 9;
	y = position % 9;
	if (position == 90)
		return (1);
	if (tab[x][y] != '.')
		return (sudoku(tab, position + 1));
	while (++nb <= '9')
	{
		if (check_line(tab, nb, x) + check_column(tab, nb, y) == 2)
		{
			if (check_block(tab, x, y, nb) == 1)
			{
				tab[x][y] = nb;
				if (sudoku(tab, position + 1))
					return (1);
			}
		}
	}
	tab[x][y] = '.';
	return (0);
}
