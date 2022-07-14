/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 16:12:07 by dbraghis          #+#    #+#             */
/*   Updated: 2016/07/09 17:23:12 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

nt		ft_is_prime(int nb)
{
	int		i;

	i = 2;
	if (nb <= 1)
	{
		return (0);
	}
	while (i <= nb / i)
	{
		if (nb % i == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	int		i;

	if (nb < 2)
	{
		nb = 2;
	}
	i = nb;
	while (i < 2 * nb)
	{
		if (ft_is_prime(i))
		{
			return (i);
		}
		i++;
	}
	return (0);
}
