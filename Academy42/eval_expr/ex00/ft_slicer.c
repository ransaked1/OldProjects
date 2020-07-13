/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slicer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 16:07:25 by dbraghis          #+#    #+#             */
/*   Updated: 2016/07/24 14:42:53 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int str_len(char *str)
{
	int		len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*str_buc1(char *str, int tmp)
{
	int		i;
	int		j;
	char	*buc1;

	i = 0;
	j = 0;
	while (i < tmp)
		i++;
	buc1 = (char *)malloc(sizeof(char) * i);
	while (j < tmp - 1)
	{
		buc1[j] = str[j];
		j++;
	}
	return (buc1);
}

char	*str_buc2(char *str, int tmp, int tmp1)
{
	int		i;
	int		j;
	char	*buc2;

	i = tmp;
	j = 0;
	while (i <= tmp1)
		i++;
	buc2 = (char *)malloc(sizeof(char) * (tmp1 - tmp));
	while (tmp <= tmp1)
	{
		buc2[j] = str[tmp];
		j++;
		tmp++;
	}
	buc2[j] = '\0';
	return (buc2);
}

char	*str_buc3(char *str, int tmp1)
{
	int		j;
	int		i;
	char	*buc3;

	j = 0;
	i = tmp1 + 1;
	while (i <= str_len(str))
		i++;
	buc3 = (char *)malloc(sizeof(char) * i);
	while (tmp1 < str_len(str))
	{
		buc3[j] = str[tmp1 + 1];
		tmp1++;
		j++;
	}
	return (buc3);
}
