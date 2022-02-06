/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 13:29:29 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/06 18:17:48 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *stack)
{
	t_list	*last;
	t_list	*tmp1;
	int		size;
	int		i;
	
	tmp1 = *stack->stack_a;
	size = ft_lstsize(tmp1);
	if (!tmp1 || size <= 1)
		return ;
	if (size == 2)
	{
		ft_pa(stack);
		return ;
	}
	last = ft_lstlast(*stack->stack_a);
	i = 0;
	while (i < size - 2)
	{
		tmp1 = tmp1->next;
		i++;
	}
	tmp1->next = NULL;
	last->next = *stack->stack_a;
	*stack->stack_a = last;
}

void	ft_rrb(t_stack *stack)
{
	t_list	*last;
	t_list	*tmp1;
	int		size;
	int		i;
	
	tmp1 = *stack->stack_b;
	size = ft_lstsize(tmp1);
	if (!tmp1 || size <= 1)
		return ;
	if (size == 2)
	{
		ft_pb(stack);
		return ;
	}
	last = ft_lstlast(*stack->stack_b);
	i = 0;
	while (i < size - 2)
	{
		tmp1 = tmp1->next;
		i++;
	}
	tmp1->next = NULL;
	last->next = *stack->stack_b;
	*stack->stack_b = last;
}

void	ft_rrr(t_stack *stack)
{
	ft_rra(stack);
	ft_rrb(stack);
}
