/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 14:07:46 by dbraghis          #+#    #+#             */
/*   Updated: 2016/07/08 20:14:10 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos] != '\0')
	{
		ft_putchar(str[pos]);
		pos++;
	}
	pos--;
	return ;
}
