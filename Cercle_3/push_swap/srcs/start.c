/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:08:26 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/18 16:10:51 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tab(t_stack *stack, int nb, int chain, int cut)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		free(stack->tab[i]);
		i++;
	}
	if (chain == 1)
	{
		ft_chainclear(stack->stack_a);
		free(stack->stack_a);
		free(stack->stack_b);
	}
	if (cut == 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	create_stack(t_stack *stack, int len)
{
	int		i;
	int		j;
	t_chain	*chain;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (stack->tab[2][i] != stack->tab[0][j])
			j++;
		chain = ft_chainnew(stack->tab[1][j]);
		if (!chain)
			free_tab(stack, 3, 1, 1);
		ft_chainadd_back(stack->stack_a, chain);
		i++;
	}
}

void	ft_sort(int *tab, int i)
{
	int	j;
	int	k;
	int	tmp;

	k = 0;
	while (k < i)
	{
		j = 0;
		while (j < i)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		k++;
	}
}

void	malloc_stack(t_stack *stack, int ac)
{
	stack->tab[0] = malloc(sizeof(int) * ac - 1);
	if (!stack->tab[0])
		free_tab(stack, 0, 0, 1);
	stack->tab[1] = malloc(sizeof(int) * ac - 1);
	if (!stack->tab[0])
		free_tab(stack, 1, 0, 1);
	stack->tab[2] = malloc(sizeof(int) * ac - 1);
	if (!stack->tab[0])
		free_tab(stack, 2, 0, 1);
	stack->stack_a = malloc(sizeof(t_chain **));
	if (!stack->stack_a)
		free_tab(stack, 3, 0, 1);
	stack->stack_b = malloc(sizeof(t_chain **));
	if (!stack->stack_b)
	{
		free(stack->stack_a);
		free_tab(stack, 3, 0, 1);
	}
	*stack->stack_a = NULL;
	*stack->stack_b = NULL;
}

void	start(t_stack *stack, int ac, char **av)
{
	int	i;
	int	nb;

	i = 0;
	malloc_stack(stack, ac);
	while (i + 1 < ac)
	{
		nb = ft_atoi(av[i + 1]);
		if (!check_int(av[i + 1]) || !check_doublon(stack->tab[0], i, nb))
		{
			free(stack->stack_a);
			free(stack->stack_b);
			free_tab(stack, 3, 0, 1);
		}
		stack->tab[0][i] = nb;
		stack->tab[1][i] = i;
		stack->tab[2][i] = nb;
		i++;
	}
	ft_sort(stack->tab[0], i - 1);
	create_stack(stack, i);
	free_tab(stack, 3, 0, 0);
}
