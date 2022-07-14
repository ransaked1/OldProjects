/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmihail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 14:04:55 by mmihail           #+#    #+#             */
/*   Updated: 2016/07/10 18:43:04 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	colle(int x, int y)
{
	int	a;
	int	b;

	a = 1;
	b = 1;
	while (b <= y)
	{
		while (a <= x)
		{
			if ((a == 1 || a == x) && b == 1)
				ft_putchar('A');
			else if ((a == 1 || a == x) && b == y)
				ft_putchar('C');
			else if (b != 1 && b != y && a != 1 && a != x)
				ft_putchar(' ');
			else
				ft_putchar('B');
			a++;
		}
		ft_putchar('\n');
		a = 1;
		b++;
	}
}
