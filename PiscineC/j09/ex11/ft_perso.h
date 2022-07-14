/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perso.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 15:50:28 by dbraghis          #+#    #+#             */
/*   Updated: 2016/07/15 15:56:33 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PERSO_H
# define FT_PERSO_H

# include <string.h>
# define SAVE_AUTIN_POWERS 20

typedef struct	s_perso
{
	char	*name;
	double	life;
	int		age;
	int		profession;
}				t_perso;

#endif
