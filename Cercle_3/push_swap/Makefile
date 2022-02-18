# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 13:33:13 by bsavinel          #+#    #+#              #
#    Updated: 2022/02/17 14:49:12 by bsavinel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	srcs/cheker.c			\
		srcs/main.c				\
		srcs/operation1.c		\
		srcs/operation2.c		\
		srcs/operation3.c		\
		srcs/print_stack.c		\
		srcs/reinjection.c		\
		srcs/second_part.c		\
		srcs/sort_2_and_3.c		\
		srcs/sort_all.c			\
		srcs/start.c			\
		srcs/up_first.c

SRCS_BONUS = 	srcs/cheker.c			\
				srcs/operation1.c		\
				srcs/operation2.c		\
				srcs/operation3.c		\
				srcs/start.c			\
				srcs/main_checker.c		\
				srcs/do_action.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

DEPS = $(SRCS:.c=.d)

DEPS_BONUS = $(SRCS_BONUS:.c=.d)

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

RM = rm -f

INCS = -I includes -I libft/includes

NAME = push_swap

CHECKER = checker

ALLLIB = libft/libft.a

all: $(NAME)

$(NAME) : $(OBJS) $(ALLLIB)
	$(CC) $(CFLAGS) $(OBJS) $(ALLLIB) -o $(NAME) $(INCS)

%.o: %.c
	$(CC) $(CFLAGS) -MMD -c $< -o $@ $(INCS)

clean :
	$(RM) $(OBJS) $(OBJS_BONUS) $(DEPS) $(DEPS_BONUS)
	$(MAKE) -C libft clean

fclean : clean
	$(RM) $(NAME) checker
	$(RM) libft/libft.a

libft/libft.a :
	$(MAKE) -C libft all

bonus : $(CHECKER)

$(CHECKER) : $(OBJS_BONUS) $(ALLLIB)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(ALLLIB) -o checker $(INCS)

re : fclean all

-include $(DEPS)
-include $(DEPS_BONUS)

.PHONY: all clean fclean re makelibft bonus
