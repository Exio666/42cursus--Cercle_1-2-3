/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 13:13:41 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/06 15:19:44 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "all_lib.h"
#include <stdio.h>

/*
 *	structure
 */

typedef struct s_stack
{
	t_list	**stack_a;
	t_list	**stack_b;
	int		madian;
	int		size;
	int		*tab[3];
}	t_stack;

/*
 *	all operation
 */

void	ft_sa(t_stack *stack);
void	ft_sb(t_stack *stack);
void	ft_ss(t_stack *stack);
void	ft_pa(t_stack *stack);
void	ft_pb(t_stack *stack);
void	ft_ra(t_stack *stack);
void	ft_rb(t_stack *stack);
void	ft_rr(t_stack *stack);
void	ft_rra(t_stack *stack);
void	ft_rrb(t_stack *stack);
void	ft_rrr(t_stack *stack);

/*
 *	start.c
 */

void	create_stack(t_stack *stack, int len);
int		check_int(char *str);
int		check_doublon(int *tab,int i, int nb);
void	ft_sort(int *tab, int i);
void	start(t_stack *stack, int ac, char **av);

#endif