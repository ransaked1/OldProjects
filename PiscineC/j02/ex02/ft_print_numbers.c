/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 17:51:56 by dbraghis          #+#    #+#             */
/*   Updated: 2016/07/07 19:20:23 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c)
{
	write(1, &c, 1);
	return ;
}

void	ft_print_numbers(void)
{
	int		number;

	number = '0';
	while (number <= '9')
	{
		ft_putchar(number);
		number++;
	}
}
