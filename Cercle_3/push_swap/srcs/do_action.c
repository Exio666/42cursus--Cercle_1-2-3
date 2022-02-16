/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:46:22 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/16 18:46:50 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_action3(char *action, t_stack *stack)
{
	if (!ft_strncmp("rra\n", action, 7))
	{
		ft_rra(stack);
		return (0);
	}
	else if (!ft_strncmp("rrb\n", action, 7))
	{
		ft_rrb(stack);
		return (0);
	}
	else if (!ft_strncmp("rrr\n", action, 7))
	{
		ft_rrr(stack);
		return (0);
	}
	else if (!ft_strncmp("\n", action, 7))
		return (3);
	else
		return (1);
}

int	do_action2(char *action, t_stack *stack)
{
	if (!ft_strncmp("pb\n", action, 7))
	{
		ft_pb(stack);
		return (0);
	}
	else if (!ft_strncmp("ra\n", action, 7))
	{
		ft_ra(stack);
		return (0);
	}
	else if (!ft_strncmp("rb\n", action, 7))
	{
		ft_rb(stack);
		return (0);
	}
	else if (!ft_strncmp("rr\n", action, 7))
	{
		ft_rr(stack);
		return (0);
	}
	else
		return (do_action3(action, stack));
}

int	do_action1(char *action, t_stack *stack)
{
	if (!ft_strncmp("sa\n", action, 7))
	{
		ft_sa(stack);
		return (0);
	}
	else if (!ft_strncmp("sb\n", action, 7))
	{
		ft_sb(stack);
		return (0);
	}
	else if (!ft_strncmp("ss\n", action, 7))
	{
		ft_ss(stack);
		return (0);
	}
	else if (!ft_strncmp("pa\n", action, 7))
	{
		ft_pa(stack);
		return (0);
	}
	else
		return (do_action2(action, stack));
}
