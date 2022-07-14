/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 16:29:09 by dbraghis          #+#    #+#             */
/*   Updated: 2016/07/19 21:56:31 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f) (int, int))
{
	while (--length > 1)
	{
		if (f(tab[length], tab[length - 1]) > 0)
			return (0);
	}
	return (1);
}
