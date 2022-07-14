/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 08:38:48 by dbraghis          #+#    #+#             */
/*   Updated: 2016/07/15 09:53:56 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_takes_place(int hour)
{
	int		h;

	if (hour > 12)
		h = hour - 12;
	if (hour == 12)
		h = 12;
	else
		h = hour;
	printf("THE FOLLOWING TAKES PLACE BETWEEN ");
	if (h < 1)
		printf("%i.00 A.M. AND %i.00 A.M.\n", h, (h + 1) % 12);
	else if (h == 11)
		printf("11.00 A.M. AND 12.00 P.M.\n");
	else if (h == 24)
		printf("12.00 A.M. AND 1.00 A.M.\n");
	else if (h == 23)
		printf("11.00 P.M. AND 12.00 A.M.\n");
	else
		printf("%i.00 P.M. AND %i.00 P.M.\n", h, (h + 1) % 12);
}
