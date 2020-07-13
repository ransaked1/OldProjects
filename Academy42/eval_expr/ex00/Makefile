# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/18 10:40:30 by dbraghis          #+#    #+#              #
#    Updated: 2016/07/24 13:14:59 by dbraghis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NUME = eval_expr

FLAGURI = -c -Wall -Wextra

SURSA = eval_expr.c ft_slicer.c ft_operation.c ft_partrans.c

SURS = eval_expr.o ft_slicer.o ft_operation.o ft_partrans.o

all: 
	gcc $(FLAGURI) $(SURSA)
	gcc -o $(NUME) $(SURS)

clean:
	/bin/rm -f $(SURS)

fclean: clean
	/bin/rm -f $(NUME)
