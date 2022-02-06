/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:08:26 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/06 15:33:11 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stack(t_stack *stack, int len)
{
	int	i;
	int	j;
	t_list	*list;

	i = 0;
	stack->stack_a = malloc(sizeof(t_list **));
	if (!stack->stack_a)
	{
		free(stack->tab[0]);
		free(stack->tab[1]);
		free(stack->tab[2]);
		return ;
	}
	stack->stack_b = malloc(sizeof(t_list **));
	if (!stack->stack_b)
	{
		free(stack->tab[0]);
		free(stack->tab[1]);
		free(stack->tab[2]);
		free(stack->stack_a);
		return ;
	}
	while (i < len)
	{
		j = 0;
		while (stack->tab[2][i] != stack->tab[0][j])
		{
			j++;
		}
		list = ft_lstnew(stack->tab[1][j]);
		ft_lstadd_back(stack->stack_a, list);
		i++;
	}
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
		if (ft_atoi_long(str) > -1000000000)
			return (0);
	}
	else if (len == 11)
	{
		if (str[i] == '-')
			return (1);
		if (ft_atoi_long(str) < 1000000000)
			return (0);
	}
	return (1);
}

int	check_doublon(int *tab, int i, int nb)
{
	int j;
	
	j = 0;
	while (j < i)
	{
		if (tab[j] == nb)
			return(0);
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
		while(j < i)
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
	if (!stack->tab[0])
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	stack->tab[1] = malloc(sizeof(int) * ac - 1);
	if (!stack->tab[0])
	{
		write(2, "Error\n", 6);
		free(stack->tab[0]);
		exit(1);
	}
	stack->tab[2] = malloc(sizeof(int) * ac - 1);
	if (!stack->tab[0])
	{
		write(2, "Error\n", 6);
		free(stack->tab[0]);
		free(stack->tab[1]);
		exit(1);
	}
	while (i + 1 < ac)
	{
		nb = ft_atoi(av[i + 1]);
		if (!check_int(av[i + 1]) || !check_doublon(stack->tab[0], i, nb))
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
	printf("%i %i %i\n",stack->tab[0][0],stack->tab[0][1],stack->tab[0][2]);
	printf("%i %i %i\n",stack->tab[1][0],stack->tab[1][1],stack->tab[1][2]);
	printf("%i %i %i\n",stack->tab[2][0],stack->tab[2][1],stack->tab[2][2]);
	create_stack(stack, i);
}