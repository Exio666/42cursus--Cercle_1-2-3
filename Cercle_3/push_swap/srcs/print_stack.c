/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:34:19 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/16 10:34:37 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack_a(t_stack *stack)
{
	t_chain	*chain;
	int		i;

	i = 0;
	chain = *stack->stack_a;
	if (!chain)
	{
		ft_printf("Stack A: VIDE\n\n");
		return ;
	}
	while (chain->next != NULL)
	{
		ft_printf("Stack A: %3i -> %i\n", i, chain->content);
		chain = chain->next;
		i++;
	}
	ft_printf("Stack A: %3i -> %i\n\n", i, chain->content);
}

void	print_stack_b(t_stack *stack)
{
	t_chain	*chain;
	int		i;

	i = 0;
	chain = *stack->stack_b;
	if (!chain)
	{
		ft_printf("Stack B: VIDE\n\n");
		return ;
	}
	while (chain->next != NULL)
	{
		ft_printf("Stack B: %3i -> %i\n", i, chain->content);
		chain = chain->next;
		i++;
	}
	ft_printf("Stack B: %3i -> %i\n\n", i, chain->content);
}

void	print_stack(t_stack *stack)
{
	print_stack_a(stack);
	print_stack_b(stack);
}
