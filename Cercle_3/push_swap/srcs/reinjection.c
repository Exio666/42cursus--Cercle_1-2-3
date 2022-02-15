/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reinjection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:05:28 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/15 17:19:39 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	up_a_down_b(t_stack *stack, t_option *option, int size_b)
{
	while (option->choice.nb_stack_a > 0)
	{
		ft_ra(stack);
		ft_printf("ra\n");
		option->choice.nb_stack_a--;
	}
	if (option->choice.nb_stack_b != 0)
		option->choice.nb_stack_b = size_b - option->choice.nb_stack_b;
	while (option->choice.nb_stack_b > 0)
	{
		ft_rrb(stack);
		ft_printf("rrb\n");
		option->choice.nb_stack_b--;
	}
	ft_pa(stack);
	ft_printf("pa\n");
}

void	up_b_down_a(t_stack *stack, t_option *option, int size_a)
{
	while (option->choice.nb_stack_b > 0)
	{
		ft_rb(stack);
		ft_printf("rb\n");
		option->choice.nb_stack_b--;
	}
	if (option->choice.nb_stack_a != 0)
		option->choice.nb_stack_a = size_a - option->choice.nb_stack_a;
	while (option->choice.nb_stack_a > 0)
	{
		ft_rra(stack);
		ft_printf("rra\n");
		option->choice.nb_stack_a--;
	}
	ft_pa(stack);
	ft_printf("pa\n");
}

void	up_b_and_a(t_stack *stack, t_option *option)
{
	while (option->choice.nb_stack_b > 0 && option->choice.nb_stack_a > 0)
	{
		ft_rr(stack);
		ft_printf("rr\n");
		option->choice.nb_stack_b--;
		option->choice.nb_stack_a--;
	}
	while (option->choice.nb_stack_b > 0)
	{
		ft_rb(stack);
		ft_printf("rb\n");
		option->choice.nb_stack_b--;
	}
	while (option->choice.nb_stack_a > 0)
	{
		ft_ra(stack);
		ft_printf("ra\n");
		option->choice.nb_stack_a--;
	}
	ft_pa(stack);
	ft_printf("pa\n");
}

void	down_b_and_a(t_stack *stack, t_option *option, int size_a, int size_b)
{
	if (option->choice.nb_stack_b != 0)
		option->choice.nb_stack_b = size_b - option->choice.nb_stack_b;
	if (option->choice.nb_stack_a != 0)
		option->choice.nb_stack_a = size_a - option->choice.nb_stack_a;
	while (option->choice.nb_stack_b > 0 && option->choice.nb_stack_a > 0)
	{
		ft_rrr(stack);
		ft_printf("rrr\n");
		option->choice.nb_stack_b--;
		option->choice.nb_stack_a--;
	}
	while (option->choice.nb_stack_b > 0)
	{
		ft_rrb(stack);
		ft_printf("rrb\n");
		option->choice.nb_stack_b--;
	}
	while (option->choice.nb_stack_a > 0)
	{
		ft_rra(stack);
		ft_printf("rra\n");
		option->choice.nb_stack_a--;
	}
	ft_pa(stack);
	ft_printf("pa\n");
}

void	reinjection(t_stack *stack, t_option *option)
{
	int	size_a;
	int	size_b;

	size_a = ft_chainsize(*stack->stack_a);
	size_b = ft_chainsize(*stack->stack_b);
	if (size_b == option->choice.nb_stack_b)
		option->choice.nb_stack_b = 0;
	if (size_a == option->choice.nb_stack_a)
		option->choice.nb_stack_a = 0;
	if (option->choice.choice == 1)
		up_a_down_b(stack, option, size_b);
	else if (option->choice.choice == 2)
		up_b_down_a(stack, option, size_a);
	else if (option->choice.choice == 3)
		up_b_and_a(stack, option);
	else if (option->choice.choice == 4)
		down_b_and_a(stack, option, size_a, size_b);
}
