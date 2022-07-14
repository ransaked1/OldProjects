/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 14:33:09 by dbraghis          #+#    #+#             */
/*   Updated: 2016/07/16 18:14:38 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_totalstring(char *str)
{
	int i;
	int nr;

	i = 0;
	nr = 0;
	while (str[i])
	{
		while (str[i] == 9 || str[i] == 10 || str[i] == 32)
			i++;
		while (str[i] && str[i] != 9 && str[i] != 10 && str[i] != 32)
		{
			nr++;
			i++;
		}
	}
	return (nr);
}

int		ft_totalcuvint(char *str, int i)
{
	int nr;

	nr = 0;
	while (str[i] && str[i] != 9 && str[i] != 10 && str[i] != 32)
	{
		nr++;
		i++;
	}
	return (nr);
}

void	init(int *a, int *b)
{
	*a = 0;
	*b = 0;
}

char	**ft_split_whitespaces(char *str)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	if ((tab = (char**)malloc(sizeof(char*) * ft_totalstring(str) + 1)) == NULL)
		return (NULL);
	init(&i, &j);
	while (str[i])
	{
		while (str[i] && (str[i] == 9 || str[i] == 10 || str[i] == 32))
			i++;
		if (str[i])
		{
			k = 0;
			tab[j] = (char*)malloc(sizeof(char) * ft_totalcuvint(str, i) + 1);
			if (tab[j] == NULL)
				return (NULL);
			while (str[i] && str[i] != 9 && str[i] != 10 && str[i] != 32)
				tab[j][k++] = str[i++];
			tab[j++][k] = '\0';
		}
	}
	tab[j] = 0;
	return (tab);
}
