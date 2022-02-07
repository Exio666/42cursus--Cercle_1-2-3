/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_and_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:49:58 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/07 18:26:08 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack *stack)
{
	ft_sa(stack);
	ft_printf("sa\n");
}

void	sort_3(t_stack *stack)
{
	t_list	*first;

	first = *stack->stack_a;
	if (first->content == 2)
	{
		ft_ra(stack);
		ft_printf("ra\n");
	}
	first = *stack->stack_a;
	if (first->next->content == 2)
	{
		ft_rra(stack);
		ft_printf("rra\n");
	}
	first = *stack->stack_a;
	if (!cheker_sort(stack))
	{
		ft_sa(stack);
		ft_printf("pa\n");
	}
}
