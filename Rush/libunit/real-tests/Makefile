# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/08 14:56:36 by dhubleur          #+#    #+#              #
#    Updated: 2022/01/09 20:09:07 by bsavinel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.c \
			$(addprefix ft_isalpha/, \
				00_launcher.c \
				01_isalpha_yes_cap_test.c \
				02_isalpha_yes_nocap_test.c \
				03_isalpha_no_test.c \
				ft_isalpha.c) \
			$(addprefix ft_isascii/, \
				00_launcher.c \
				01_isascii_yes_test.c \
				02_isascii_no_test.c \
				ft_isascii.c) \
			$(addprefix ft_isdigit/, \
				00_launcher.c \
				01_isdigit_0_test.c \
				02_isdigit_no_test.c \
				03_isdigit_9_test.c \
				ft_isdigit.c) \
			$(addprefix ft_strlen/, \
				00_launcher.c \
				01_strlen_longstr_test.c \
				02_strlen_strnull_test.c \
				03_strlen_emptystr_test.c \
				ft_strlen.c) \
			$(addprefix ft_isprint/, \
				00_launcher.c \
				01_isprint_yes_test.c \
				02_isprint_no_test.c \
				03_isprint_limitinf_test.c \
				04_isprint_limitsup_test.c \
				ft_isprint.c) \
			$(addprefix ft_tolower/, \
				00_launcher.c \
				01_tolower_up_test.c \
				02_tolower_low_test.c \
				03_tolower_notchar_test.c \
				ft_tolower.c) \
			$(addprefix ft_toupper/, \
				00_launcher.c \
				01_toupper_up_test.c \
				02_toupper_low_test.c \
				03_toupper_notchar_test.c \
				ft_toupper.c) \
			$(addprefix ft_atoi/, \
				00_launcher.c \
				01_atoi_zero_test.c \
				02_atoi_positive_test.c \
				03_atoi_negative_test.c \
				04_atoi_intmin_test.c \
				05_atoi_intmax_test.c \
				06_atoi_overflow_test.c \
				07_atoi_plus_test.c \
				08_atoi_plus_minus_test.c \
				09_atoi_whitespaces_test.c \
				ft_atoi.c)

OBJS	=	${SRCS:.c=.o}
INCL	=	-I../framework

NAME	=	real-tests
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