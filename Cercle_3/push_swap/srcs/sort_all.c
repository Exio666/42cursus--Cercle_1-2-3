/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:30:33 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/08 17:27:06 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	proche1(t_stack *stack)
{
	t_chain *for_ra;
	t_chain *for_rra;

	for_ra = *stack->stack_a;
	for_rra = *stack->stack_a;
	while (for_ra->content >= stack->median && for_rra->content >= stack->median)
	{
		if (for_rra->back == NULL)
			for_rra = ft_chainlast(for_rra);
		else
			for_rra = for_rra->back;
		for_ra = for_ra->next;
	}
	if (!(for_ra->content >= stack->median - 1))
		return (1);
	else
		return (-1);
}

int	proche2(t_stack *stack)
{
	t_chain *for_ra;
	t_chain *for_rra;

	for_ra = *stack->stack_a;
	for_rra = *stack->stack_a;
	while (for_ra->content <= stack->median + 1 && for_rra->content <= stack->median + 1)
	{
		if (for_rra->back == NULL)
			for_rra = ft_chainlast(for_rra);
		else
			for_rra = for_rra->back;
		for_ra = for_ra->next;
	}
	if (!(for_ra->content <= stack->median + 1))
		return (1);
	else
		return (-1);
}

void	push_median(t_stack *stack)
{
	t_chain	*stack_a;
	int		i;
	int		sens;
	
	i = 0;
	while (i < stack->median)
	{
		sens = proche1(stack);
		stack_a = *stack->stack_a;
		while (stack_a->content >= stack->median)
		{
			if (sens == 1)
			{
				ft_ra(stack);
				ft_printf("ra\n");
			}
			else
			{
				ft_rra(stack);
				ft_printf("rra\n");
			}
			stack_a = *stack->stack_a;
		}
		ft_pb(stack);
		ft_printf("pb\n");
		stack->action++;
		i++;
	}
	ft_ra(stack);
	ft_printf("ra\n");
	while (i < stack->size - 3)
	{
		ft_pb(stack);
		ft_printf("pb\n");
		stack->action++;
		i++;
	}
	sort_3(stack);
}

void	sort_all(t_stack *stack)
{
	push_median(stack);
}
