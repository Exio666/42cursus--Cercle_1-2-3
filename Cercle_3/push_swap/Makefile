# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 13:33:13 by bsavinel          #+#    #+#              #
#    Updated: 2022/01/04 13:38:30 by bsavinel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

CLIB = ar -rcs

INCS = includes

NAME = push_swap.a

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