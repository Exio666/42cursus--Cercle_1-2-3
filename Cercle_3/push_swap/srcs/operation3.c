/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 13:29:29 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/15 14:45:28 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *stack)
{
	t_chain	*last;
	t_chain	*first;
	int		size;

	first = *stack->stack_a;
	size = ft_chainsize(first);
	if (!first || size <= 1)
		return ;
	last = ft_chainlast(*stack->stack_a);
	last->back->next = NULL;
	last->next = first;
	last->back = NULL;
	first->back = last;
	*stack->stack_a = last;
}

void	ft_rrb(t_stack *stack)
{
	t_chain	*last;
	t_chain	*first;
	int		size;

	first = *stack->stack_b;
	size = ft_chainsize(first);
	if (!first || size <= 1)
		return ;
	last = ft_chainlast(*stack->stack_b);
	last->back->next = NULL;
	last->next = first;
	last->back = NULL;
	first->back = last;
	*stack->stack_b = last;
}

void	ft_rrr(t_stack *stack)
{
	ft_rra(stack);
	ft_rrb(stack);
}
