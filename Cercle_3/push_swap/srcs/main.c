/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:41:51 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/16 10:34:57 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stack;

	if (ac <= 1)
		return (1);
	start(&stack, ac, av);
	if (!cheker_sort(&stack))
	{
		stack.size = ft_chainsize(*stack.stack_a);
		stack.median = stack.size / 2;
		if (ac <= 3)
			sort_2(&stack);
		else if (ac <= 4)
			sort_3(&stack);
		else
			sort_all(&stack);
	}
	ft_chainclear(stack.stack_a);
	ft_chainclear(stack.stack_b);
	free(stack.stack_a);
	free(stack.stack_b);
	return (0);
}
