/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 19:06:08 by dbraghis          #+#    #+#             */
/*   Updated: 2016/07/13 20:28:38 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_swap(char *x, char *y)
{
	int		a;

	a = *x;
	*x = *y;
	*y = a;
}

int		main(char argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		j = i + 1
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]))
			{
				ft_strswap(*argv[i], *argv[j]);
			}
			j++;
		}
		j = 0;
		while (argv[i][j] != '\0')
		{
			ft_putchar(argv[i][j]);
			ft_putchar('\n');
			i++;
		}
		return (0);
	}
}
