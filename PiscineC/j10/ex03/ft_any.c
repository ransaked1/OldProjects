/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 14:35:27 by dbraghis          #+#    #+#             */
/*   Updated: 2016/07/19 21:55:14 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_any(char **tab, int (*f) (char*))
{
	int		i;

	i = 0;
	while (tab[i] != '\0')
	{
		if (f(tab[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}