# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 15:20:52 by bsavinel          #+#    #+#              #
#    Updated: 2021/12/22 12:43:41 by bsavinel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =			srcs/ft_printf.c		\
				srcs/char.c				\
				srcs/decimal.c			\
				srcs/hexa_and_void.c	\
				srcs/struct_info.c		\
				srcs/unsign.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

CLIB = ar -rcs

NAME = libftprintf.a

INCS = includes

all: $(NAME)

$(NAME): makelibft $(OBJS)
	$(CLIB) $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCS) -I libft/includes

clean :
	$(RM) $(OBJS)
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