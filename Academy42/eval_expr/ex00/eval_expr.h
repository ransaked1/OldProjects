/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 15:27:21 by dbraghis          #+#    #+#             */
/*   Updated: 2016/07/24 13:13:51 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_EXPR_H
# define EVAL_EXPR_H

int		str_len(char *str);
char	*str_buc1(char *str, int tmp);
char	*str_buc2(char *str, int tmp, int tmp1);
char	*str_buc3(char *str, int tmp1);
int		ft_atoi(char str);
char	*ft_operation(char *str);
char	*ft_putnbr(char *str, int x);

#endif
