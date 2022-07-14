/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afisare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsaptefr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 12:29:46 by vsaptefr          #+#    #+#             */
/*   Updated: 2016/07/24 21:35:14 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i = i + 1;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int		i;
	int		result;

	result = 0;
	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		result = result + s1[i] - s2[i];
		if (result != 0)
			return (1);
		i++;
	}
	return (result);
}

void	ft_putnbr(int nbr)
{
	int		aux;
	int		nr;
	int		size;

	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = nbr * -1;
	}
	aux = nbr;
	size = 1;
	while (aux / 10 > 0)
	{
		size = size * 10;
		aux = aux / 10;
	}
	while (size > 0)
	{
		nr = 0;
		nr = nbr / size;
		ft_putchar(nr + '0');
		nbr = nbr % size;
		size = size / 10;
	}
}

void	ft_afis(char *colle, int a, int b)
{
	ft_putstr(colle);
	ft_putstr(" [");
	ft_putnbr(a);
	ft_putstr("] [");
	ft_putnbr(b);
	ft_putchar(']');
}
