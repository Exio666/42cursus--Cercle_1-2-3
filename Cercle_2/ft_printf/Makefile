# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 15:20:52 by bsavinel          #+#    #+#              #
#    Updated: 2021/12/08 10:02:45 by bsavinel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =			srcs/ft_printf.c		\
				srcs/char.c				\
				srcs/decimal.c			\
				srcs/hexa_and_void.c	\
				srcs/putnbr.c			\
				srcs/flag.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

RM = rm -f

CLIB = ar -rcs

NAME = libftprintf.a

INCS = Includes

all: $(NAME)

$(NAME): $(OBJS)
	$(CLIB) $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCS)

clean :
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(RM) $(NAME)

bonus : all

re : fclean all

.PHONY: all clean fclean re