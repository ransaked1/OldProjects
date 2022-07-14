/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 15:53:00 by dbraghis          #+#    #+#             */
/*   Updated: 2016/07/13 16:41:24 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	int		j;
	int		k;
	int		i;

	i = 1;
	k = argc - 1;
	while (k > 0)
	{
		j = 0;
		while (argv[k][j])
		{
			ft_putchar(argv[k][j]);
			j++;
		}
		k--;
		ft_putchar('\n');
	}
	return (0);
}
