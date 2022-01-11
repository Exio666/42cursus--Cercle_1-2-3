/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:44:43 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/08 20:51:24 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int	protect_fork(int child_pid, t_test_list *lst)
{
	if (child_pid == -1)
	{
		free_test_list(lst);
		ft_putstr("Fork error\n");
		return (0);
	}
	return (1);
}

void	exec_child(t_test_list *lst, t_test *test)
{
	int		(*ft_test)(void);

	ft_test = test->test;
	free_test_list(lst);
	exit (ft_test());
}

int	exec_test(t_test_list *lst, t_test	*test, int *counter, int *ok)
{
	int		wait_status;
	pid_t	child_pid;

	child_pid = 1;
	while (test != NULL)
	{
		if (child_pid != 0)
		{
			child_pid = fork();
			if (!protect_fork(child_pid, lst))
				return (0);
		}
		wait(&wait_status);
		if (child_pid == 0)
			exec_child(lst, test);
		else
		{	
			print_result(lst, test, wait_status, ok);
			(*counter)++;
		}
		test = test->next_test;
	}
	return (1);
}

int	launch_test(t_test_list *lst)
{
	int		counter;
	int		ok;
	t_test	*test;

	counter = 0;
	ok = 0;
	if (!lst || !lst->test)
	{
		free_test_list(lst);
		ft_putstr("Not initialized tests list\n");
		return (-1);
	}
	test = lst->test;
	if (!exec_test(lst, test, &counter, &ok))
		return (-1);
	return (print_end_test(ok, counter, lst));
}
