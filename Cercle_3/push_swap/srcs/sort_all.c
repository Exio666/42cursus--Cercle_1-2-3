/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:30:33 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/13 14:07:56 by bsavinel         ###   ########.fr       */
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

int	find_most_lower(int nb, t_stack *stack, t_option *option)
{
	t_chain	*stack_a;
	int		lower;
	int 	i;

	i = 0;
	stack_a = *stack->stack_a;
	lower = stack->size + 5;
	while (stack_a)
	{
		if (stack_a->content > nb && stack_a->content < lower)
		{
			lower = stack_a->content;
			option->tab_cost[1] = i;
		}
		stack_a = stack_a->next;
		i++;
	}
	i = 0;
	if (lower == stack->size + 5)
	{
		stack_a = *stack->stack_a;
		while (stack_a)
		{
			if (stack_a->content < lower)
			{
				lower = stack_a->content;
				option->tab_cost[1] = i;
			}
			stack_a = stack_a->next;
		}
		i++;
	}
	return (lower);
}

void	feed_option(t_option *option, t_stack *stack)
{

}

void	second_part(t_stack *stack)
{
	t_chain		*stack_b;
	t_option	option;

	stack_b = *stack->stack_b;
	option.tab_cost[3] = 0;
	while (stack_b)
	{
		while (stack_b)
		{
			option.corespond = find_most_lower(stack_b->content, stack, &option);
			feed_option(&option, stack);
			stack_b = stack_b->next;
			option.tab_cost[3]++;
		}
		reinjection(stack, &option);
		stack_b = *stack->stack_b;
	}
}

void	sort_all(t_stack *stack)
{
	push_median(stack);
	second_part(stack);
	up_first(stack);
}
