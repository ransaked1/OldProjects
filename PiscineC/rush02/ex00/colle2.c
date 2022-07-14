/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsaptefr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 09:16:42 by vsaptefr          #+#    #+#             */
/*   Updated: 2016/07/24 21:38:33 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "colle.h"

int		g_a;
int		g_b;
int		g_i;
char	*g_tab;

char	*colle2(int x, int y)
{
	g_tab = (char*)malloc(4096);
	g_a = 1;
	g_i = 0;
	while (g_a <= y)
	{
		g_b = 1;
		while (g_b <= x)
		{
			if ((g_a == 1 && g_b == 1) || (g_b == x && g_a == 1))
				g_tab[g_i] = 'A';
			else if ((g_a == y && g_b == 1) || (g_b == x && g_a == y))
				g_tab[g_i] = 'C';
			else if (g_b != 1 && g_a != x && g_b != 1 && g_a != y)
				g_tab[g_i] = ' ';
			else
				g_tab[g_i] = 'B';
			g_b++;
			g_i++;
		}
		g_tab[g_i] = '\n';
		g_i++;
		g_a++;
	}
	return (g_tab);
}
