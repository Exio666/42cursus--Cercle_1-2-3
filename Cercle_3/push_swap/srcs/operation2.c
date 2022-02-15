/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:41:57 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/15 14:47:03 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *stack)
{
	t_chain	*first;
	t_chain	*last;
	int		size;

	first = *stack->stack_a;
	size = ft_chainsize(first);
	if (!first || size <= 1)
		return ;
	last = ft_chainlast(first);
	*stack->stack_a = first->next;
	first->next->back = NULL;
	first->next = NULL;
	last->next = first;
	first->back = last;
}

void	ft_rb(t_stack *stack)
{
	t_chain	*first;
	t_chain	*last;
	int		size;

	first = *stack->stack_b;
	size = ft_chainsize(first);
	if (!first || size <= 1)
		return ;
	last = ft_chainlast(first);
	*stack->stack_b = first->next;
	first->next->back = NULL;
	first->next = NULL;
	last->next = first;
	first->back = last;
}

void	ft_rr(t_stack *stack)
{
	ft_ra(stack);
	ft_rb(stack);
}
