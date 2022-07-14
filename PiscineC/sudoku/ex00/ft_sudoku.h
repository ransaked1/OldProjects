/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sudoku.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsandu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 20:32:20 by tsandu            #+#    #+#             */
/*   Updated: 2016/07/23 15:26:17 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_SUDOKU_H
# define __FT_SUDOKU_H
# include <unistd.h>

void		ft_putchar(char c);
void		ft_putstr(char *str);
void		afisare(char **tab);
int			check_line(char **tab, char nb, int x);
int			check_column(char **tab, char nb, int y);
int			check_block(char **tab, int x, int y, char nb);
int			check_grila(char **tab, int n);
int			sudoku(char **tab, int position);
#endif
