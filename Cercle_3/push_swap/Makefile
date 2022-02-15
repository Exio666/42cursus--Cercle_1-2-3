# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 13:33:13 by bsavinel          #+#    #+#              #
#    Updated: 2022/02/15 17:16:55 by bsavinel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	srcs/cheker.c			\
		srcs/main.c				\
		srcs/operation1.c		\
		srcs/operation2.c		\
		srcs/operation3.c		\
		srcs/reinjection.c		\
		srcs/second_part.c		\
		srcs/sort_2_and_3.c		\
		srcs/sort_all.c			\
		srcs/start.c			\
		srcs/up_first.c

OBJS = $(SRCS:.c=.o)

DEPS = $(SRCS:.c=.d)

CC = gcc

CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address

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