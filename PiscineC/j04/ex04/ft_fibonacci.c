/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 14:06:25 by dbraghis          #+#    #+#             */
/*   Updated: 2016/07/09 17:21:26 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_fibonacci(int nb)
{
	if (nb < 0)
	{
		return (-1);
	}
	if (nb <= 2)
	{
		return (nb);
	}
	return (ft_fibonacci(nb - 1) + ft_fibonacci(nb - 2));
}
