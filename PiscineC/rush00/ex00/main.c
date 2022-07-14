/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmihail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 11:53:45 by mmihail           #+#    #+#             */
/*   Updated: 2016/07/10 18:44:51 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		colle(int x, int y);

int		main(void)
{
	colle(5, 3);
	ft_putchar('\n');
	colle(5, 1);
	ft_putchar('\n');
	colle(1, 1);
	ft_putchar('\n');
	colle(1, 5);
	ft_putchar('\n');
	colle(4, 4);
	ft_putchar('\n');
	return (0);
}
