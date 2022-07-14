# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/18 10:40:30 by dbraghis          #+#    #+#              #
#    Updated: 2016/07/24 14:40:33 by dbraghis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NUME = eval_expr

FLAGURI = -c -Wall -Wextra -Werror

SURSA = eval_expr.c ft_operation.c

SURS = eval_expr.o ft_operation

all: 
	gcc $(FLAGURI) $(SURSA)
	gcc -o $(NUME) $(SURS)

clean:
	/bin/rm -f $(SURS)

fclean: clean
	/bin/rm -f $(NUME)
