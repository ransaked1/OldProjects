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

void	v16(char **dest)
{
	dest[0][0] = '#';
	dest[0][1] = '#';
	dest[0][2] = '#';
	dest[1][1] = '#';
}

void	v17(char **dest)
{
	dest[0][1] = '#';
	dest[1][0] = '#';
	dest[1][1] = '#';
	dest[2][1] = '#';
}

void	v18(char **dest)
{
	dest[0][1] = '#';
	dest[1][0] = '#';
	dest[1][1] = '#';
	dest[1][2] = '#';
}

void	v19(char **dest)
{
	dest[0][0] = '#';
	dest[1][0] = '#';
	dest[2][0] = '#';
	dest[1][1] = '#';
}

void	clear_map(char **dest)
{
	dest[0][0] = '.';
	dest[0][1] = '.';
	dest[0][2] = '.';
	dest[0][3] = '.';
	dest[1][0] = '.';
	dest[1][1] = '.';
	dest[1][2] = '.';
	dest[1][3] = '.';
	dest[2][0] = '.';
	dest[2][1] = '.';
	dest[2][2] = '.';
	dest[2][3] = '.';
	dest[3][0] = '.';
	dest[3][1] = '.';
	dest[3][2] = '.';
	dest[3][3] = '.';
}
