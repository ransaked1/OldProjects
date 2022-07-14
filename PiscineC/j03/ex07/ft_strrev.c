/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 14:47:09 by dbraghis          #+#    #+#             */
/*   Updated: 2016/07/08 20:21:34 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int		pos;
	int		i;
	char	str_rev;

	str_rev = "";
	pos = 0;
	i = 0;
	while (str[pos] != '\0')
	{
		pos++;
	}
	pos--;
	while (pos >= 0)
	{
		str_rev[i] = str[pos];
		i++;
		pos--;
	}
	return (str_rev);
}
