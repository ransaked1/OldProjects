/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 12:00:02 by dbraghis          #+#    #+#             */
/*   Updated: 2016/07/24 14:42:32 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "eval_expr.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	str_par(char *str)
{
	int		i;
	int		tmp;
	int		tmp1;
	int		stop;
	char	*oper;

	tmp = 0;
	tmp1 = 0;
	i = 0;
	stop = 0;
	while (stop == 0)
	{
		if (str[i] == 40)
			tmp = i;
		if (str[i] == 41)
		{
			tmp1 = i;
			stop = 1;
		}
		i++;
	}
	oper = str_buc2(str, tmp, tmp1);
	printf("%s", ft_operation(oper));
}

int		main(int argc, char **argv)
{
	int		rez;

	rez = argc;
	//rez = calcul(argv[1]);
	str_par(argv[1]);
	return (0);
}
