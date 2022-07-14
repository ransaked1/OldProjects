/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 10:17:09 by dbraghis          #+#    #+#             */
/*   Updated: 2016/07/12 16:24:13 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*start;
	char	*nstr;

	while (*str)
	{
		start = str;
		nstr = to_find;
		while (*str && *nstr && *str == *nstr)
		{
			str++;
			nstr++;
		}
		if (!*nstr)
			return (start);
		str = start + 1;
	}
	return (str);
}
