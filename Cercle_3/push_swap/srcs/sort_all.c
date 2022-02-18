/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:30:33 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/18 10:06:18 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	proche(t_stack *stack)
{
	t_chain	*for_ra;
	t_chain	*for_rra;

	for_ra = *stack->stack_a;
	for_rra = *stack->stack_a;
	while (for_ra->content >= stack->median
		&& for_rra->content >= stack->median)
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

void	push_under(t_stack *stack)
{
	int		sens;
	t_chain	*stack_a;

	sens = proche(stack);
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
}

void	push_median(t_stack *stack)
{
	int		i;

	i = 0;
	while (i < stack->median && i < stack->size - 3)
	{
		push_under(stack);
		i++;
	}
	ft_ra(stack);
	ft_printf("ra\n");
	while (i < stack->size - 3)
	{
		ft_pb(stack);
		ft_printf("pb\n");
		i++;
	}
	sort_3(stack);
}

int	clacul_choice(int place_a, int place_b)
{
	if (place_a > place_b)
	{
		return (place_a);
	}
	return (place_b);
}

void	sort_all(t_stack *stack)
{
	push_median(stack);
	second_part(stack);
	up_first(stack);
}
