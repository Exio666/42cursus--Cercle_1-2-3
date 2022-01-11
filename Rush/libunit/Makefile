# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/08 09:30:06 by dhubleur          #+#    #+#              #
#    Updated: 2022/01/09 10:56:58 by dhubleur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	$(addprefix framework/, \
					runner1.c \
					runner2.c \
					test_utils.c \
					ft_print.c)

SRCS_BONUS	=	$(addprefix framework/, \
					runner1_bonus.c \
					runner2_bonus.c \
					test_utils.c \
					ft_print.c)

OBJS		=	${SRCS:.c=.o}

OBJS_BONUS	=	${SRCS_BONUS:.c=.o}

NAME	= 	libunit.a

CC		= 	gcc
CFLAGS	+= 	-Wall -Wextra -Werror

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

$(NAME):	${OBJS} 
				ar rc ${NAME} ${OBJS}
				ranlib ${NAME}

bonus:	${OBJS_BONUS} 
				ar rc ${NAME} ${OBJS_BONUS}
				ranlib ${NAME}

clean:
				rm -f ${OBJS} ${OBJS_BONUS}

fclean:		clean
				rm -f ${NAME}

re:				fclean all

.PHONY:			all clean fclean re