/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:39:17 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/17 11:35:12 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_in_prog(t_stack *stack)
{
	ft_putstr_fd("Error\n", 2);
	ft_chainclear(stack->stack_a);
	ft_chainclear(stack->stack_b);
	free(stack->stack_a);
	free(stack->stack_b);
	exit(1);
}

void	make_action(t_stack *stack)
{
	char	*action;
	int		error;

	error = 0;
	action = get_next_line(0);
	if (!action)
		return ;
	while (action)
	{
		error = do_action1(action, stack);
		free(action);
		if (error == 1)
			error_in_prog(stack);
		else if (error == 3)
			break ;
		action = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_stack	stack;

	if (ac <= 1)
		return (0);
	start(&stack, ac, av);
	make_action(&stack);
	if (cheker_sort(&stack))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_chainclear(stack.stack_a);
	ft_chainclear(stack.stack_b);
	free(stack.stack_a);
	free(stack.stack_b);
}
