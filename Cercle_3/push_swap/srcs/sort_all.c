/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:30:33 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/14 17:44:44 by bsavinel         ###   ########.fr       */
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
	option->place[0] = 0;
	while (stack_a)
	{
		if (stack_a->content > nb && stack_a->content < lower)
		{
			lower = stack_a->content;
			option->place[0] = i;
			if (i == 12)
				printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
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
				if (i == 12)
				printf("******************************************************\n");
			}
			stack_a = stack_a->next;
			i++;
		}
	}
	return (lower);
}

int	clacul_choice(int place_a, int place_b)
{
	if (place_a > place_b)
	{
		return(place_a);
	}
	return (place_b);
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
		printf("cost: %i\n", test.cost);
		test.cost = clacul_choice(option->place[0], option->place[1]);
	}
	if (clacul_choice(size_a - option->place[0],size_b - option->place[1]) < test.cost)
	{
		test.choice = 4;
		printf("cost: %i\n", test.cost);
		test.cost = clacul_choice(size_a - option->place[0],size_b - option->place[1]);
	}
	if (option->choice.cost < test.cost)
		return ;
	option->choice = test;
	option->choice.nb_stack_a = option->place[0];
	option->choice.nb_stack_b = option->place[1]; 
}

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
	print_stack(stack);
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
	print_stack(stack);
	ft_pa(stack);
	ft_printf("pa\n");
}

void	up_b_and_a(t_stack *stack, t_option *option)
{
	printf("*******    %i\n", option->choice.nb_stack_a);
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
	print_stack(stack);
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
	print_stack(stack);
	ft_pa(stack);
	ft_printf("pa\n");
}


void	reinjection(t_stack *stack, t_option *option)
{
	int			size_a;
	int			size_b;

	printf("choice : %i\n a: %i\n b: %i\n", option->choice.choice,option->choice.nb_stack_a,option->choice.nb_stack_b );
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

void	second_part(t_stack *stack)
{
	t_chain		*stack_b;
	t_option	option;
	int 		i;

	i  = 0;
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
		printf("====avant====\n\n");
		print_stack(stack);
		reinjection(stack, &option);
		stack_b = *stack->stack_b;
		printf("====apres====\n\n");
		print_stack(stack);
		if (i == 12)
			exit(1);
		i++;
	}
}

void	sort_all(t_stack *stack)
{
	push_median(stack);
	print_stack(stack);
	second_part(stack);
	//up_first(stack);
}
