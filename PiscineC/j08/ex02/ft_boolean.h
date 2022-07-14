/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 15:21:07 by dbraghis          #+#    #+#             */
/*   Updated: 2016/07/20 13:41:41 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H
# include <unistd.h>

# define TRUE		1
# define FALSE		0
# define SUCCESS	0
# define EVEN_MSG	"I have a pair number of arguments.\n"
# define ODD_MDG	"I have an impair number of arguments.\n"
# define EVEN(x)	(!((x) % 2))

typedef int		t_bool;
#endif
