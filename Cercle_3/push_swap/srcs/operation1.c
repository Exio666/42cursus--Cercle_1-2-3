/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:41:54 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/06 17:26:30 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *stack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (!*stack->stack_a)
		return ;
	tmp1 = *stack->stack_a;
	tmp2 = tmp1->next;
	*stack->stack_a = tmp2;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
}

void	ft_sb(t_stack *stack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (!*stack->stack_b)
		return ;
	tmp1 = *stack->stack_b;
	tmp2 = tmp1->next;
	*stack->stack_b = tmp2;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
}

void	ft_ss(t_stack *stack)
{
	ft_sb(stack);
	ft_sa(stack);
}

void	ft_pb(t_stack *stack)
{
	t_list	*stack_a;

	stack_a = *stack->stack_a;
	if (!stack_a)
		return ;
	*stack->stack_a = stack_a->next;
	stack_a->next = *stack->stack_b;
	*stack->stack_b = stack_a;
}

void	ft_pa(t_stack *stack)
{
	t_list	*stack_b;

	stack_b = *stack->stack_b;
	if (!stack_b)
		return ;
	*stack->stack_b = stack_b->next;
	stack_b->next = *stack->stack_a;
	*stack->stack_a = stack_b;
}
