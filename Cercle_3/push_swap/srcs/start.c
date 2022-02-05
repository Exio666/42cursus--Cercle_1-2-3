/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:08:26 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/05 15:01:32 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stack(t_stack *stack)
{
	
}

int	check_int(char *str)
{
	int len;
	int i;

	i = 0;
	len = ft_strlen(str);
	if (len > 12)
		return (0);
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if(!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (len == 12)
	{
		if (str[i] != '-')
			return (0);
		if (ft_atoi_unsign(str) > -1000000000)
			return (0);
	}
	else if (len == 11)
	{
		if (str[i] == '-')
			return (1);
		if (ft_atoi_unsign(str) < 1000000000)
			return (0);
	}
	return (1);
}

int	check_doublon(int *tab,int i, int nb)
{
	int j;
	
	j = 0;
	while (j < i)
	{
		if (tab[j] == nb)
			j++;
	}
	return (1);
}

void	ft_sort(int *tab, int i)
{
	int j;
	int k;
	int tmp;
	
	k = 0;
	while(k < i)
	{
		j = 0;
		while(j < i - 1)
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

void	start(t_stack *stack, int ac, char **av)
{
	int	i;
	int	nb;

	i = 0;
	stack->tab[0] = malloc(sizeof(int) * ac - 1);
	if (stack->tab[0])
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	stack->tab[1] = malloc(sizeof(int) * ac - 1);
	if (stack->tab[0])
	{
		write(2, "Error\n", 6);
		free(stack->tab[0]);
		exit(1);
	}
	stack->tab[2] = malloc(sizeof(int) * ac - 1);
	if (stack->tab[0])
	{
		write(2, "Error\n", 6);
		free(stack->tab[0]);
		free(stack->tab[1]);
		exit(1);
	}
	while (i + 1 < ac)
	{
		nb = ft_atoi(av[i + 1]);
		if (!check_int(av[i + 1]) || !check_doublon(stack->tab[0], i, nb));
		{
			free(stack->tab[0]);
			free(stack->tab[1]);
			free(stack->tab[2]);
			write(2, "Error\n", 6);
			exit(1);
		}
		stack->tab[0][i] = nb;
		stack->tab[1][i] = i;
		stack->tab[2][i] = nb;
		i++;
	}
	ft_sort(stack->tab[0], i - 1);
	create_stack(stack);
}