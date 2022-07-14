/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 12:05:34 by dbraghis          #+#    #+#             */
/*   Updated: 2016/07/12 16:27:45 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		alpha(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (0);
	if (c >= 'a' && c <= 'z')
		return (0);
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z' && (i == 0 || alpha(str[i - 1])))
		{
			str[i] = str[i] - 32;
			i++;
		}
		else
			i++;
	}
	return (str);
}
