/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_partrans.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 12:57:43 by dbraghis          #+#    #+#             */
/*   Updated: 2016/07/24 14:24:16 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

int		ft_prior(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '/' || str[i] == '*' || str[i] == '%')
			return (1);
		i++;
	}
	return (0);
}

int		ft_calcx(char *str, int i)
{
	int		x;

	x = -666;
	if (str[i] == '/')
		x = ft_atoi(str[i - 2]) / ft_atoi(str[i + 2]);
	if (str[i] == '*')
		x = ft_atoi(str[i - 2]) * ft_atoi(str[i + 2]);
	if (str[i] == '%')
		x = ft_atoi(str[i - 2]) % ft_atoi(str[i + 2]);
	return (x);
}

int		ft_calcx1(char *str, int i)
{
	int		x;

		x = -666;
	if (str[i] == '+')
		x = ft_atoi(str[i - 2]) + ft_atoi(str[i + 2]);
	if (str[i] == '-')
		x = ft_atoi(str[i - 2]) - ft_atoi(str[i + 2]);
	return (x);
}

char	*ft_operation(char *str)
{
	int		i;
	int		x;
	char	*nbuc2;

	i = 0;
	x = 0;
	while (str[i] != '\0')
	{
		if (ft_prior(str))
			x = ft_calcx(str, i);
		else
			x = ft_calcx1(str, i);
		if (x != -666)
		{
			nbuc2 = ft_putnbr(str, x);
			str = nbuc2;
			if (str_len(str) == 1)
				return (str);
			else
				return (ft_operation(str));
		}
		i++;
	}
	return (str);
}
