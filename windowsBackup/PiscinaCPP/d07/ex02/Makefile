# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/24 09:46:26 by dbraghis          #+#    #+#              #
#    Updated: 2017/07/28 19:13:57 by dbraghis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = array

CC=clang++

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

SRC=*.cpp

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC)

clean:
	@$(RM) *.o

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean
