/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Name.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbreahna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 20:59:32 by rbreahna          #+#    #+#             */
/*   Updated: 2016/07/27 12:53:54 by rbreahna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	v1(char **dest)
{
	dest[0][0] = '#';
	dest[0][1] = '#';
	dest[0][2] = '#';
	dest[0][3] = '#';
}

void	v2(char **dest)
{
	dest[0][0] = '#';
	dest[1][0] = '#';
	dest[2][0] = '#';
	dest[3][0] = '#';
}

void	v3(char **dest)
{
	dest[0][0] = '#';
	dest[0][1] = '#';
	dest[1][0] = '#';
	dest[1][1] = '#';
}

void	v4(char **dest)
{
	dest[0][0] = '#';
	dest[0][1] = '#';
	dest[0][2] = '#';
	dest[1][2] = '#';
}

void	v5(char **dest)
{
	dest[0][1] = '#';
	dest[1][1] = '#';
	dest[2][0] = '#';
	dest[2][1] = '#';
}
