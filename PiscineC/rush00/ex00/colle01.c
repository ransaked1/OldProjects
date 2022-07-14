/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmihail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 17:01:07 by mmihail           #+#    #+#             */
/*   Updated: 2016/07/10 17:01:52 by mmihail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	check(int a, int b, int x, int y)
{
	if (x > 1 && a == x && b == y && y > 1)
		ft_putchar('/');
	else if ((a == x && b == 1) || (b == y && a == 1))
		ft_putchar('\\');
	else if (b != 1 && b != y && a != 1 && a != x)
		ft_putchar(' ');
	else
		ft_putchar('*');
	return ;
}

void	colle(int x, int y)
{
	int	a;
	int	b;

	a = 2;
	b = 1;
	if (x != 0 && y != 0)
		ft_putchar('/');
	while (b <= y && y != 0 && x != 0)
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
