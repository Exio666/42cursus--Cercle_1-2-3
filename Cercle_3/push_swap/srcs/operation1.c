/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:41:54 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/16 19:10:57 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *stack)
{
	t_chain	*tmp1;
	t_chain	*tmp2;

	if (!*stack->stack_a)
		return ;
	tmp1 = *stack->stack_a;
	if (ft_chainsize(tmp1) < 2)
		return ;
	tmp2 = tmp1->next;
	*stack->stack_a = tmp2;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	tmp2->back = NULL;
	tmp1->back = tmp2;
	if (tmp1->next)
		tmp1->next->back = tmp1;
}

void	ft_sb(t_stack *stack)
{
	t_chain	*tmp1;
	t_chain	*tmp2;

	if (!*stack->stack_b)
		return ;
	tmp1 = *stack->stack_b;
	if (ft_chainsize(tmp1) < 2)
		return ;
	tmp2 = tmp1->next;
	*stack->stack_b = tmp2;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	tmp2->back = NULL;
	tmp1->back = tmp2;
	if (tmp1->next)
		tmp1->next->back = tmp1;
}

void	ft_ss(t_stack *stack)
{
	ft_sb(stack);
	ft_sa(stack);
}

void	ft_pb(t_stack *stack)
{
	t_chain	*stack_b;
	t_chain	*stack_a;

	stack_a = *stack->stack_a;
	if (!stack_a)
		return ;
	if (*stack->stack_b)
	{
		stack_b = *stack->stack_b;
		stack_b->back = stack_a;
		stack_a->back = NULL;
	}
	*stack->stack_a = stack_a->next;
	stack_a->next = *stack->stack_b;
	*stack->stack_b = stack_a;
}

void	ft_pa(t_stack *stack)
{
	t_chain	*stack_b;
	t_chain	*stack_a;

	stack_b = *stack->stack_b;
	if (!stack_b)
		return ;
	if (*stack->stack_a)
	{
		stack_a = *stack->stack_a;
		stack_a->back = stack_b;
		stack_b->back = NULL;
	}
	*stack->stack_b = stack_b->next;
	stack_b->next = *stack->stack_a;
	*stack->stack_a = stack_b;
}
