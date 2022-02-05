# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 13:33:13 by bsavinel          #+#    #+#              #
#    Updated: 2022/02/05 13:15:42 by bsavinel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	

OBJS = $(SRCS:.c=.o)

DEPS = $(SRCS:.c=.d)

CC = cc

CFLAGS = -Wall -Wextra -Werror -O3

RM = rm -f

CLIB = ar -rcs

LIB = fdf.a

INCS = -I includes -I minilibx -I libft/includes

NAME = push_swap

ALLLIB = libft/libft.a minilibx/libmlx_Linux.a

all: $(NAME)

$(NAME) : makelibft $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(ALLLIB) $(LIBIXFLAGS) -o $(NAME) $(INCS)

%.o: %.c
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@ $(INCS)

clean :
	$(RM) $(OBJS) $(DEPS)
	$(MAKE) -C libft clean

fclean : clean
	$(RM) $(NAME)
	$(RM) libft/libft.a

makelibft :
	$(MAKE) -C libft all

bonus : all

re : fclean all

-include $(DEPS)

.PHONY: all clean fclean re makelibft makeminilibx bonus