# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsaptefr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/23 10:28:09 by vsaptefr          #+#    #+#              #
#    Updated: 2016/07/24 21:32:08 by dbraghis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = colle-2

EXEC = colle-00 colle-01 colle-02 colle-03 colle-04

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -o colle-00 colle-00.c main.c ft_putchar.c $(FLAG)
	gcc -o colle-01 colle-01.c main.c ft_putchar.c $(FLAG)
	gcc -o colle-02 colle-02.c main.c ft_putchar.c $(FLAG)
	gcc -o colle-03 colle-03.c main.c ft_putchar.c $(FLAG)
	gcc -o colle-04 colle-04.c main.c ft_putchar.c $(FLAG)

clean :
	/bin/rm -rf $(EXEC)

fclean : clean
	/bin/rm -rf $(NAME)

re : fclean all
