# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 11:02:27 by bsavinel          #+#    #+#              #
#    Updated: 2022/02/19 14:36:06 by bsavinel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	srcs/convertor.c		\
		srcs/draw_line.c		\
		srcs/end.c				\
		srcs/fdf_utils.c		\
		srcs/main.c				\
		srcs/parsing.c			\
		srcs/rotate.c			\
		srcs/select_hook.c		\
		srcs/translate_zoom.c	\
		srcs/init_zoom_trans.c	\
		srcs/color.c			\
		srcs/parsing2.c

OBJS = $(SRCS:.c=.o)

DEPS = $(SRCS:.c=.d)

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3 -O3

RM = rm -f

CLIB = ar -rcs

LIB = fdf.a

INCS = -I includes -I minilibx -I libft/includes

NAME = fdf

ALLLIB = libft/libft.a minilibx/libmlx_Linux.a

LIBIXFLAGS = -lm -lbsd -lX11 -lXext

all: $(NAME)

$(NAME) : $(OBJS) $(ALLLIB)
	$(CC) $(CFLAGS) $(OBJS) $(ALLLIB) $(LIBIXFLAGS) -o $(NAME) $(INCS)

%.o: %.c
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@ $(INCS)

clean :
	$(RM) $(OBJS) $(DEPS)
	$(MAKE) -C minilibx clean
	$(MAKE) -C libft clean

fclean : clean
	$(RM) $(NAME)
	$(RM) libft/libft.a
	$(RM) minilibx/libmlx_Linux.a
	$(RM) minilibx/libmlx.a

libft/libft.a :
	$(MAKE) -C libft all

minilibx/libmlx_Linux.a :
	$(MAKE) -C minilibx all

bonus : all

re : fclean all

-include $(DEPS)

.PHONY: all clean fclean re bonus
