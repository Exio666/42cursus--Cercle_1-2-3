/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:41:57 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/07 18:10:08 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *stack)
{
	t_list	*first;
	t_list	*last;
	int		size;
	
	first = *stack->stack_a;
	size = ft_lstsize(first);
	if (!first || size <= 1)
		return ;
	if (size == 2)
	{
		ft_sa(stack);
		return ;
	}
	last = ft_lstlast(first);
	*stack->stack_a = first->next;
	first->next = NULL;
	last->next = first;
}

void	ft_rb(t_stack *stack)
{
	t_list	*first;
	t_list	*last;
	int		size;
	
	first = *stack->stack_b;
	size = ft_lstsize(first);
	if (!first || size <= 1)
		return ;
	if (size == 2)
	{
		ft_sb(stack);
		return ;
	}
	last = ft_lstlast(first);
	*stack->stack_b = first->next;
	first->next = NULL;
	last->next = first;
}

void	ft_rr(t_stack *stack)
{
	ft_ra(stack);
	ft_rb(stack);
}
