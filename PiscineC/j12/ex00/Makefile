# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/18 10:40:30 by dbraghis          #+#    #+#              #
#    Updated: 2016/07/21 21:49:59 by dbraghis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NUME = ft_display_file

FLAGURI = -c -Wall -Wextra -Werror

SURSA = ft_display_file.c

SURS = ft_display_file.o

all: $(NUME)

$(NUME):
	gcc $(FLAGURI) $(SURSA)
	gcc -o $(NUME) $(SURS)

clean:
	/bin/rm -f $(SURS)

fclean: clean
	/bin/rm -f $(NUME)
