/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsandu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 20:32:04 by tsandu            #+#    #+#             */
/*   Updated: 2016/07/17 20:32:05 by tsandu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sudoku.h"

int		main(int argc, char **argv)
{
	if (check_grila(argv, argc))
	{
		if (sudoku(argv, 9))
			afisare(argv);
		else
		{
			ft_putstr("Error");
			ft_putchar('\n');
		}
	}
	else
	{
		ft_putstr("Error");
		ft_putchar('\n');
	}
	return (0);
}
