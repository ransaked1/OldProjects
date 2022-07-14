/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 13:54:01 by dbraghis          #+#    #+#             */
/*   Updated: 2016/07/15 16:25:14 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ultimator.h"
#include <stdlib.h>

void	ft_destroy(char ***factory)
{
	int		a;
	int		b;

	a = -1;
	while (factory[a])
	{
		b = -1;
		while (factory[a][b])
			free(factory[a][b]);
		free(factory[a]);
		a++;
	}
	free(factory);
}
