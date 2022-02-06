/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:41:51 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/06 18:15:05 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack_a(t_stack *stack)
{
	t_list	*list;
	int		i;

	i = 0;
	list = *stack->stack_a;
	if (!list)
	{
		printf("Stack A : VIDE\n\n");
		return ;
	}
	while (list->next != NULL && i < 100)
	{
		printf("Stack A: %3i : %i\n", i, list->content);
		list = list->next;
		i++;
	}
	printf("Stack A: %3i : %i\n\n", i, list->content);
}

void	print_stack_b(t_stack *stack)
{
	t_list	*list;
	int		i;

	i = 0;
	list = *stack->stack_b;
	if (!list)
	{
		printf("Stack B : VIDE\n\n");
		return ;
	}
	while (list->next != NULL && i < 100)
	{
		printf("Stack B %3i : %i\n", i, list->content);
		list = list->next;
		i++;
	}
	printf("Stack B %3i : %i\n\n", i, list->content);
}

int	main(int ac, char **av)
{
	t_stack	stack;

	if (ac <= 1)
		return (1);
	start(&stack, ac, av);
	ft_pb(&stack);
	ft_pb(&stack);
	ft_pb(&stack);
	ft_pb(&stack);
	print_stack_a(&stack);
	print_stack_b(&stack);
	printf("*******reverse a*******\n");
	ft_rra(&stack);
	printf("!!!\n");
	print_stack_a(&stack);
	print_stack_b(&stack);
	printf("*******reverse b*******\n");
	ft_rrb(&stack);
	ft_rrb(&stack);
	print_stack_a(&stack);
	print_stack_b(&stack);
	printf("*******2 reverse*******\n");
	ft_rrr(&stack);
	ft_rrr(&stack);
	print_stack_a(&stack);
	print_stack_b(&stack);
}
/*	===========================
	==== TEST PA/B  SA/B/S ====
	===========================

	print_stack_a(&stack);
	print_stack_b(&stack);
	printf("*******push b*******\n");
	ft_pb(&stack);
	ft_pb(&stack);
	ft_pb(&stack);
	print_stack_a(&stack);
	print_stack_b(&stack);
	printf("********switch********\n");
	ft_sa(&stack);
	ft_sb(&stack);
	print_stack_a(&stack);
	print_stack_b(&stack);
	printf("*******reswitch*******\n");
	ft_ss(&stack);
	print_stack_a(&stack);
	print_stack_b(&stack);
	printf("*******fin*******\n");
	ft_pa(&stack);
	ft_pa(&stack);
	ft_pa(&stack);
	print_stack_a(&stack);
	print_stack_b(&stack);
*/
