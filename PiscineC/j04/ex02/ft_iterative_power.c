/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 13:16:31 by dbraghis          #+#    #+#             */
/*   Updated: 2016/07/09 17:20:20 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int		tmp;

	tmp = nb;
	if (power < 0)
	{
		return (0);
	}
	while (power > 0)
	{
		power--;
		nb = nb * tmp;
	}
	return (nb);
}
