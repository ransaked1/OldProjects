/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmihail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 19:40:20 by mmihail           #+#    #+#             */
/*   Updated: 2016/07/10 21:01:54 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		check(int a, int b, int x, int y)
{
	if (a == 1 && (b == y || b == 1))
		ft_putchar('A');
	else if (a == x && (b == 1 || b == y))
		ft_putchar('C');
	else if ((b == 1 || b == y) && a != 1 && a != x)
		ft_putchar('B');
	else if (b != 1 && b != y && a != 1 && a != x)
		ft_putchar(' ');
	else
		ft_putchar('B');
	return (0);
}

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
			check(a, b, x, y);
			a++;
		}
		ft_putchar('\n');
		a = 1;
		b++;
	}
}
