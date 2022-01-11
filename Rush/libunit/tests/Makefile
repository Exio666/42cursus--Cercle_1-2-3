# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/08 14:56:36 by dhubleur          #+#    #+#              #
#    Updated: 2022/01/09 11:52:41 by dhubleur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.c \
			$(addprefix strlen/, \
				00_launcher.c \
				01_basic_test.c \
				02_null_test.c) \
			$(addprefix atoi/, \
				00_launcher.c \
				01_basic_test.c \
				02_plus_test.c) \
			$(addprefix bug/, \
				00_launcher.c \
				01_timeout_test.c \
				02_bus_test.c \
				03_sigfpe_test.c \
				04_sigpipe_test.c \
				05_sigill_test.c \
				06_sigabrt_test.c)

OBJS	=	${SRCS:.c=.o}
INCL	=	-I../framework

NAME	=	tests
CC		=	gcc

CFLAGS += -Wall -Wextra -Werror

RM		=	rm -f

LIBUNIT	=	../libunit.a

.c.o:
				${CC} ${CFLAGS} ${INCL} -c $< -o ${<:.c=.o}

all:		${NAME}

$(NAME):	${OBJS} ${LIBUNIT}
				${CC} -o ${NAME} ${OBJS} ${LIBUNIT}

$(LIBUNIT):
				$(MAKE) -C ../. bonus

clean:
				${RM} ${OBJS}

fclean:		clean
				${RM} ${NAME}

fcleanlib:	fclean
				make -C ../. fclean

re:			fclean all

test:		${NAME}
				./${NAME}

.PHONY:		all clean fclean re fcleanlib test