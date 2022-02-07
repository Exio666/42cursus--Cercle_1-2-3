# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 13:33:13 by bsavinel          #+#    #+#              #
#    Updated: 2022/02/07 10:02:55 by bsavinel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	srcs/main.c			\
		srcs/start.c		\
		srcs/operation1.c	\
		srcs/operation2.c	\
		srcs/operation3.c

OBJS = $(SRCS:.c=.o)

DEPS = $(SRCS:.c=.d)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

INCS = -I includes -I libft/includes

NAME = push_swap

ALLLIB = libft/libft.a

all: $(NAME)

$(NAME) : makelibft $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(ALLLIB) -o $(NAME) $(INCS)

%.o: %.c
	$(CC) $(CFLAGS) -MMD -c $< -o $@ $(INCS)

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

.PHONY: all clean fclean re makelibft bonus