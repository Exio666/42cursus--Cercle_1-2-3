/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:21:56 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/08 14:35:13 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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