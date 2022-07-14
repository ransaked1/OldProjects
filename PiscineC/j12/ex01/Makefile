# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/18 10:40:30 by dbraghis          #+#    #+#              #
#    Updated: 2016/07/21 22:45:57 by dbraghis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NUME = ft_cat

FLAGURI = -c -Wall -Wextra -Werror

SURSA = ft_cat.c

SURS = ft_cat.o

all: $(NUME)

$(NUME):
	gcc $(FLAGURI) $(SURSA)
	gcc -o $(NUME) $(SURS)

clean:
	/bin/rm -f $(SURS)

fclean: clean
	/bin/rm -f $(NUME)
