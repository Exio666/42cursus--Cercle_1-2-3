# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 16:55:25 by bsavinel          #+#    #+#              #
#    Updated: 2022/01/15 12:31:07 by bsavinel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

tes = 	truc1.c\
		truc2.c

tes1 = 	cestbon.c\
		truc4.c

test1 = $(tes1:.c=.o)

test = $(tes:.c=.o)

all: $(test) $(test1)
	@echo coucou $* $* -MMD -MP -MF /deps/<name-file>

clean:
	rm -f $(test) $(test1)
%.o: %.c
	gcc -c $< -o $@