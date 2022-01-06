# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 12:21:51 by bsavinel          #+#    #+#              #
#    Updated: 2022/01/05 12:18:15 by bsavinel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MS = srcs/main_server.c

MSO = $(MS:.c=.o)

EXTS = server

MC = srcs/main_client.c

MCO = $(MC:.c=.o) 

EXTC = client

INCS = includes

CFLAGS = -Wall -Wextra -Werror

CC = gcc

RM = rm -rf

all : $(EXTC) $(EXTS)

$(EXTC) : $(MCO) makelibft
	$(CC) $(CFLAGS) $(MCO) libft/libft.a -o $(EXTC)

$(EXTS) : $(MSO) makelibft
	$(CC) $(CFLAGS) $(MSO) libft/libft.a -o $(EXTS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I libft/includes -I $(INCS)

clean :
	$(RM) $(MCO) $(MSO)
	$(MAKE) -C libft clean

fclean : clean
	$(RM) $(EXTC) $(EXTS)
	$(RM) libft/libft.a

makelibft :
	$(MAKE) -C libft all

bonus : all

re : fclean all

.PHONY: all clean fclean re makelibft