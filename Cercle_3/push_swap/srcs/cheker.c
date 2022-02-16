/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:21:56 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/16 10:36:19 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_int(char *str)
{
	int			len;
	int			i;
	long int	nb;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i] == '0')
		i++;
	len = ft_strlen(&str[i]);
	if (len > 10)
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	nb = ft_atoi_long(str);
	if (nb < -2147483648 || nb > 2147483647)
		return (0);
	return (1);
}

int	cheker_sort(t_stack *stack)
{
	t_chain	*to_check;
	int		i;

	to_check = *stack->stack_b;
	if (to_check)
		return (0);
	to_check = *stack->stack_a;
	i = 0;
	while (to_check)
	{
		if (to_check->content != i)
			return (0);
		to_check = to_check->next;
		i++;
	}	
	return (1);
}

int	cheker_sort_3a(t_stack *stack)
{
	t_chain	*to_check;

	to_check = *stack->stack_a;
	if (to_check->content > to_check->next->content
		|| to_check->next->content > to_check->next->next->content)
		return (0);
	return (1);
}

int	check_doublon(int *tab, int i, int nb)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (tab[j] == nb)
			return (0);
		j++;
	}
	return (1);
}
