/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsaptefr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 10:40:08 by vsaptefr          #+#    #+#             */
/*   Updated: 2016/07/24 21:40:02 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "colle.h"

int		g_a;
int		g_b;
int		g_i;
char	*g_tab;

char	*colle1(int x, int y)
{
	g_tab = (char*)malloc(4096);
	g_a = 1;
	g_i = 0;
	while (g_a <= y)
	{
		while (g_b <= x)
		{
			if ((g_a == 1 && g_b == 1) || (g_b == x && g_a == y && g_a != 1 && g_b != 1))
				g_tab[g_i] = '/';
			else if ((g_a == 1 && g_b == x) || (g_b == 1 && g_a == y))
				g_tab[g_i] = '\\';
			else if (g_b != 1 && g_b != x && g_a != 1 && g_a != y)
				g_tab[g_i] = ' ';
			else
				g_tab[g_i] = '*';
			g_b++;
			g_i++;
		}
		g_tab[g_i] = '\n';
		g_i++;
		g_a++;
	}
	return (g_tab);
}
