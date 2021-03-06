/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ncuvinte.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 19:10:55 by dbraghis          #+#    #+#             */
/*   Updated: 2016/11/11 19:33:53 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ncuvinte(char const *s, char c)
{
	int		n;
	int		k;
	int		i;

	k = 0;
	n = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (k == 1 && s[i] == c)
			k = 0;
		if (k == 0 && s[i] != c)
		{
			k = 1;
			n++;
		}
		i++;
	}
	return (n);
}
