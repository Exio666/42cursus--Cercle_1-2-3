/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 09:32:14 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/09 17:41:02 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_BONUS_H
# define LIBUNIT_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>

# define TIMEOUT 1

/*
 * 	Structur
 */

typedef struct s_test
{
	char			*test_name;
	int				(*test)(void);
	struct s_test	*next_test;
}	t_test;

typedef struct s_test_list
{
	char	*function_name;
	t_test	*test;
}	t_test_list;

/*
 *	print.c
 */

void		ft_putnbr(int n);
void		ft_putstr(char *str);

/*
 *	unit_test
 */

int			launch_test(t_test_list *lst);
t_test_list	*init_test_list(char *tested_function_name);
t_test_list	*add_test(t_test_list *test_list, char *test_name,
				int (*test)(void));
t_test_list	*free_test_list(t_test_list *test_list);
void		print_signal_error(int exit_code);
void		print_result(t_test *test, int wait_status, int *ok);
int			print_end_test(int ok, int counter, t_test_list *lst);

#endif