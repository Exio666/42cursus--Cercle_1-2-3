# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 11:02:27 by bsavinel          #+#    #+#              #
#    Updated: 2022/01/07 15:51:33 by bsavinel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	srcs/algo_bresenham.c	\
		srcs/main.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

CLIB = ar -rcs

LIBFDF = fdf.a

INCS = includes

ALLINCS = -I includes -I minilibx -I libft/includes

NAME = fdf

all: $(NAME)

$(NAME) : makelibft makeminilibx $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a minilibx/libmlx_Linux.a -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(ALLINCS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(ALLINCS)

clean :
	$(RM) $(OBJS)
	$(RM) $(MAINO)
	$(MAKE) -C libft clean

fclean : clean
	$(RM) $(NAME)
	$(RM) libft/libft.a

makelibft :
	$(MAKE) -C libft all

makeminilibx :
	$(MAKE) -C minilibx all

bonus : all

re : fclean all

.PHONY: all clean fclean re makelibft