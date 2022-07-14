/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmihail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 14:04:55 by mmihail           #+#    #+#             */
/*   Updated: 2016/07/10 18:38:28 by dbraghis         ###   ########.fr       */
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
			if ((a == 1 || a == x) && (b == y || b == 1))
				ft_putchar('o');
			else if ((a == x || a == 1) && b != 1 && b != y)
				ft_putchar('|');
			else if (b != 1 && b != y && a != 1 && a != x)
				ft_putchar(' ');
			else
				ft_putchar('-');
			a++;
		}
		ft_putchar('\n');
		a = 1;
		b++;
	}
}
