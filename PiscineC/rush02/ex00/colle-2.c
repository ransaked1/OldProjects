/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle-2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsaptefr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 11:21:20 by vsaptefr          #+#    #+#             */
/*   Updated: 2016/07/24 21:40:37 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_functions.h"
#include "colle.h"
#define BUF_SIZE 1

void	ft_tabcmp(char *buf, int x, int y)
{
	int		i;
	int		more;

	i = 0;
	more = 0;
	if (ft_strcmp(buf, colle0(x, y)) == 0)
	{
		ft_afis("[colle-00]", x, y);
		more++;
	}
	if (ft_strcmp(buf, colle1(x, y)) == 0)
	{
		if (more > 0)
			ft_putstr(" || ");
		ft_afis("[colle-01]", x, y);
		more++;
	}
	if (ft_strcmp(buf, colle2(x, y)) == 0)
	{
		if (more > 0)
			ft_putstr(" || ");
		ft_afis("[colle-02]", x, y);
		more++;
	}
	if (ft_strcmp(buf, colle3(x, y)) == 0)
	{
		if (more > 0)
			ft_putstr(" || ");
		ft_afis("[colle-03]", x, y);
		more++;
	}
	if (ft_strcmp(buf, colle4(x, y)) == 0)
	{
		if (more > 0)
			ft_putstr(" || ");
		ft_afis("[colle-04]", x, y);
		more++;
	}
	if (more == 0)
		ft_putstr("aucune");
	ft_putchar('\n');
}

int main()
{
	char	*mem;
	char	buf[BUF_SIZE + 1];
	int		ret;
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	mem = (char*)malloc(BUF_SIZE);
	while ((ret = read(0, buf, BUF_SIZE)))
	{
		if (buf[0] == '\n')
			y++;
		if (buf[0] != '\n')
			x++;
		buf[ret] = '\0';
		mem[i] = buf[0];
		i++;
	}
	mem[i] = '\0';
	if (y != 0)
		x = x / y;
	ft_tabcmp(mem, x, y);
	return (0);
}
