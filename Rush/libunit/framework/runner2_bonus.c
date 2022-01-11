/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:43:16 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/09 11:51:13 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit_bonus.h"

void	print_signal_error(int exit_code)
{
	int	sig_code;

	ft_putstr("\033[31m");
	sig_code = WTERMSIG(exit_code);
	if (sig_code == SIGBUS)
		ft_putstr("[SIGBUS]\n");
	else if (sig_code == SIGSEGV)
		ft_putstr("[SIGSEGV]\n");
	else if (sig_code == SIGFPE)
		ft_putstr("[SIGFPE]\n");
	else if (sig_code == SIGPIPE)
		ft_putstr("[SIGPIPE]\n");
	else if (sig_code == SIGILL)
		ft_putstr("[SIGILL]\n");
	else if (sig_code == SIGABRT)
		ft_putstr("[SIGABRT]\n");
	else
		ft_putstr("(signal)\n");
	ft_putstr("\033[0m");
}

void	print_ok(t_test *test, int *ok)
{
	ft_putstr(test->test_name);
	ft_putstr(" : \033[32m[OK]\033[0m\n");
	(*ok)++;
}

void	print_result(t_test *test, int wait_status, int *ok)
{
	ft_putstr("\t- ");
	if (WIFEXITED(wait_status))
	{
		if (WEXITSTATUS(wait_status) == 0)
			print_ok(test, ok);
		else if (WEXITSTATUS(wait_status) == SIGALRM)
		{
			ft_putstr(test->test_name);
			ft_putstr(" : \033[31m[TIMEOUT]\033[0m\n");
		}
		else
		{
			ft_putstr(test->test_name);
			ft_putstr(" : \033[31m[KO]\033[0m\n");
		}
	}
	else
	{
		ft_putstr(test->test_name);
		ft_putstr(" : ");
		print_signal_error(wait_status);
	}
}

int	print_end_test(int ok, int counter, t_test_list *lst)
{
	ft_putstr("\n");
	ft_putnbr(ok);
	ft_putstr("/");
	ft_putnbr(counter);
	ft_putstr(" valid tests !\n");
	free_test_list(lst);
	if (ok != counter)
		return (-1);
	return (0);
}
