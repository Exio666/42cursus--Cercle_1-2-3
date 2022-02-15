/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_part.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:09:44 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/15 17:20:18 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_most_lower(int nb, t_stack *stack, t_option *option)
{
	t_chain	*stack_a;
	int		lower;
	int		i;

	i = 0;
	stack_a = *stack->stack_a;
	lower = stack->size + 5;
	option->place[0] = 0;
	while (stack_a)
	{
		if (stack_a->content > nb && stack_a->content < lower)
		{
			lower = stack_a->content;
			option->place[0] = i;
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
				option->place[0] = i;
			}
			stack_a = stack_a->next;
			i++;
		}
	}
	return (lower);
}

void	feed_option(t_option *option, t_stack *stack)
{
	int			size_a;
	int			size_b;
	t_choice	test;

	size_a = ft_chainsize(*stack->stack_a);
	size_b = ft_chainsize(*stack->stack_b);
	test.choice = 1;
	test.cost = option->place[0] + size_b - option->place[1];
	if (option->place[1] + size_a - option->place[0] < test.cost)
	{
		test.choice = 2;
		test.cost = option->place[1] + size_a - option->place[0];
	}
	if (clacul_choice(option->place[0], option->place[1]) < test.cost)
	{
		test.choice = 3;
		test.cost = clacul_choice(option->place[0], option->place[1]);
	}
	if (clacul_choice(size_a - option->place[0], size_b - option->place[1]) < test.cost)
	{
		test.choice = 4;
		test.cost = clacul_choice(size_a - option->place[0], size_b - option->place[1]);
	}
	if (option->choice.cost < test.cost)
		return ;
	option->choice = test;
	option->choice.nb_stack_a = option->place[0];
	option->choice.nb_stack_b = option->place[1];
}

void	second_part(t_stack *stack)
{
	t_chain		*stack_b;
	t_option	option;
	int			i;

	i = 0;
	stack_b = *stack->stack_b;
	while (stack_b != NULL)
	{
		option.place[1] = 0;
		option.choice.cost = INT_MAX;
		while (stack_b != NULL)
		{
			option.corespond = find_most_lower(stack_b->content, stack, &option);
			feed_option(&option, stack);
			stack_b = stack_b->next;
			option.place[1]++;
		}
		reinjection(stack, &option);
		stack_b = *stack->stack_b;
		i++;
	}
}
