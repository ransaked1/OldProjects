/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 12:49:37 by dbraghis          #+#    #+#             */
/*   Updated: 2016/07/22 16:07:34 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	int		i;

	i = argc;
	while (**argv)
	{
		ft_putchar(**argv);
		(*argv)++;
	}
	ft_putchar('\n');
	return (0);
}
