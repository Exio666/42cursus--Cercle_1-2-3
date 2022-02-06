/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:41:51 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/06 16:04:05 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_stack *stack)
{
	t_list *list;
	int i;
	
	i = 0;
	list = *stack->stack_a;
	if(!list)
		return;
	while (list->next != NULL)
	{
		printf("Element %3i : %i\n", i, list->content);
		list = list->next;
		i++;
	}
	printf("Element %3i : %i\n", i, list->content);
}

int	main(int ac, char **av)
{
	t_stack	stack;

	if (ac <= 1)
		return (1);
	start(&stack, ac, av);
	print_stack(&stack);
}
