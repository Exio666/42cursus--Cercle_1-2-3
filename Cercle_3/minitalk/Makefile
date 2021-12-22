# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 12:21:51 by bsavinel          #+#    #+#              #
#    Updated: 2021/12/22 12:46:01 by bsavinel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	minitalk_utils.c

MS = main_serveur.c

MC = main_client.c

INCS = includes

MSO = $(MS:.c=.o)

MCO = $(MC:.c=.o) 

OBJS = $(SRCS:.c=.o)

EXTC = client

EXTS = serveur

CFLAGS = -Wall -Wextra -Werror

CC = gcc

RM = rm -rf

all : $(EXTC) $(EXTS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCS)

$(EXTC) : $(OBJS) $(MCO)
	$(CC) $(CFLAGS) $(OBJS) $(MCO) -o $(ETC)

$(EXTS) : $(OBJS) $(MSO)
	$(CC) $(CFLAGS) $(OBJS) $(MSO) -o $(ETS)

clean :
	$(RM) $(OBJS) $(MCO) $(MVO)

fclean : clean
	$(RM) $(EXTC) $(EXTV)

re : fclean all

.PHONY: all clean fclean re
