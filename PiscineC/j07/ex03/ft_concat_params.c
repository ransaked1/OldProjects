/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 13:59:38 by dbraghis          #+#    #+#             */
/*   Updated: 2016/07/14 15:54:26 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_marime(int argc, char **argv)
{
	int		i;
	int		j;
	int		mar;

	i = 1;
	j = 0;
	mar = 0;
	while (i < argc)
	{
		while (argv[i][j])
			j++;
		mar = mar + j;
		j = 0;
		i++;
	}
	return (mar);
}

void	ft_tab(int argc, char **argv, char *str, int mar)
{
	int		i;
	int		j;
	int		z;

	i = 0;
	j = 1;
	z = 0;
	while (i < mar)
	{
		while (j < argc)
		{
			while (argv[j][z])
			{
				str[i] = argv[j][z];
				j++;
				z++;
			}
			str[i] = '\n';
			z = 0;
			j++;
		}
	}
	str[i] = '\0';
}

char	*ft_concat_params(int argc, char **argv)
{
	char	*str;
	int		mar;

	mar = ft_marime(argc, argv);
	str = (char*)malloc(sizeof(str) + (mar * argc - 1));
	ft_tab(argc, argv, str, mar);
	return (str);
}
