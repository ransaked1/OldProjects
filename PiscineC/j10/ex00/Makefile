# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/18 10:40:30 by dbraghis          #+#    #+#              #
#    Updated: 2016/07/19 22:00:33 by dbraghis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE = libft.a

FLAGURI = -c -Wall -Wextra -Werror

HEADER = includes

OPTIUNI = -I$(HEADER)

SURSA = srcs/ft_putchar.c srcs/ft_strlen.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_swap.c

COMPIL = ft_putchar.o ft_strlen.o ft_putstr.o ft_strcmp.o ft_swap.o

all:
	gcc $(FLAGURI) $(SURSA) $(OPTIUNI)
	ar rc $(FILE) $(COMPIL)
	ranlib $(FILE)

clean:
	/bin/rm -f $(COMPIL)

fclean: clean
	/bin/rm -f $(FILE)

re: fclean all
