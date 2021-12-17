# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 15:20:52 by bsavinel          #+#    #+#              #
#    Updated: 2021/12/17 17:32:14 by bsavinel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =			srcs/ft_printf.c		\
				srcs/char.c				\
				srcs/decimal.c			\
				srcs/hexa_and_void.c	\
				srcs/putnbr.c			\
				srcs/struc_info.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

RM = rm -f

CLIB = ar -rcs

NAME = libftprintf.a

INCS = includes

all: $(NAME)

$(NAME): $(OBJS) makelibft
	$(CLIB) $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCS) -I libft/includes

clean :
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(MAKE) -C libft clean

fclean : clean
	$(RM) $(NAME)
	$(RM) libft/libft.a

makelibft :
	$(MAKE) -C libft all
	cp libft/libft.a $(NAME)

bonus : all

re : fclean all

.PHONY: all clean fclean re makelibft