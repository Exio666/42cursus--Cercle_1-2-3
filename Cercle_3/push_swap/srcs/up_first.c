/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_first.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:56:38 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/15 17:19:42 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_down_a(t_stack *stack)
{
	t_chain	*stack_a;

	stack_a = *stack->stack_a;
	while (stack_a && stack_a->content != 0)
	{
		ft_ra(stack);
		ft_printf("ra\n");
		stack_a = *stack->stack_a;
	}
}

void	ft_up_a(t_stack *stack)
{
	t_chain	*stack_a;

	stack_a = *stack->stack_a;
	while (stack_a && stack_a->content != 0)
	{
		ft_rra(stack);
		ft_printf("rra\n");
		stack_a = *stack->stack_a;
	}
}

void	up_first(t_stack *stack)
{
	int		up;
	int		down;
	t_chain	*stack_a;

	stack_a = *stack->stack_a;
	down = 0;
	up = 1;
	while (stack_a && stack_a->content != 0)
	{
		stack_a = stack_a->next;
		down++;
	}
	stack_a = ft_chainlast(stack_a);
	while (stack_a && stack_a->content != 0)
	{
		stack_a = stack_a->back;
		up++;
	}
	if (down <= up)
		ft_down_a(stack);
	else
		ft_up_a(stack);
}
