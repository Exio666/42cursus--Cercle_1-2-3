/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_and_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:49:58 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/08 18:02:21 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack *stack)
{
	ft_sa(stack);
	ft_printf("sa\n");
	stack->action++;
}

void	sort_3(t_stack *stack)
{
	t_chain	*first;
	t_chain	*last;

	first = *stack->stack_a;
	last = ft_chainlast(first);
	if (first->content > first->next->content && first->content > last->content)
	{
		ft_ra(stack);
		ft_printf("ra\n");
		stack->action++;
	}
	else if (first->next->content > first->content && first->next->content > last->content)
	{
		ft_rra(stack);
		ft_printf("rra\n");
		stack->action++;
	}
	first = *stack->stack_a;
	if (!cheker_sort_3a(stack))
	{
		ft_sa(stack);
		ft_printf("sa\n");
		stack->action++;
	}
}
