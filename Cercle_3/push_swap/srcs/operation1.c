/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:41:54 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/04 14:05:09 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list *a, t_list *b)
{
	t_list	*first;
	t_list	*second;
	
	(void)b;
	if (ft_lstsize(a) > 1);
	{
		first = a;
		second = a->next;
		first->next = second;
		second->next = first;	
	}	
}

void	ft_sb(t_list *a, t_list *b)
{
	t_list	*first;
	t_list	*second;
	
	(void)a;
	if (ft_lstsize(b) > 1);
	{
		first = b;
		second = b->next;
		first->next = second;
		second->next = first;	
	}	
}

void	ft_ss(t_list *a, t_list *b)
{
	ft_sb(a, b);
	ft_sa(a, b);
}
