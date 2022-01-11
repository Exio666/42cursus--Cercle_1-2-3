/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:43:16 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/09 10:40:05 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	print_signal_error(int exit_code)
{
	int	sig_code;

	sig_code = WTERMSIG(exit_code);
	if (sig_code == SIGBUS)
		ft_putstr("[SIGBUS]\n");
	else if (sig_code == SIGSEGV)
		ft_putstr("[SIGSEGV]\n");
	else
		ft_putstr("(signal)\n");
}

void	print_ok(t_test_list *lst, t_test *test, int *ok)
{
	ft_putstr(lst->function_name);
	ft_putstr(" : ");
	ft_putstr(test->test_name);
	ft_putstr(" : [OK]\n");
	(*ok)++;
}

void	print_result(t_test_list *lst, t_test *test,
							int wait_status, int *ok)
{
	if (WIFEXITED(wait_status))
	{
		if (WEXITSTATUS(wait_status) == 0)
			print_ok(lst, test, ok);
		else
		{
			ft_putstr(lst->function_name);
			ft_putstr(" : ");
			ft_putstr(test->test_name);
			ft_putstr(" : [KO]\n");
		}
	}
	else
	{
		ft_putstr(lst->function_name);
		ft_putstr(" : ");
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
	ft_putstr(" tests checked\n");
	free_test_list(lst);
	if (ok != counter)
		return (-1);
	return (0);
}
