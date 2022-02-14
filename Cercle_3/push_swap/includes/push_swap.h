/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 13:13:41 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/14 11:08:35 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "all_lib.h"
#include <stdio.h>
# include <limits.h>

/*
 *	structure
 */

typedef struct s_stack
{
	t_chain	**stack_a;
	t_chain	**stack_b;
	int		median;
	int		size;
	int		action;
	int		*tab[3];
}	t_stack;

/*
= 1 ->￼↑↓
= 2 ->￼↓↑
= 3 -> ↑↑
= 4 ->￼↓↓
*/
typedef struct s_choice
{
	int choice;
	int cost;
	int nb_stack_a;
	int nb_stack_b;
}	t_choice;

typedef struct s_option
{
	int	corespond;
	int place[2];
	int tab_cost[4];
	t_choice choice;
}	t_option;


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
int		check_doublon(int *tab, int i, int nb);
void	ft_sort(int *tab, int i);
void	start(t_stack *stack, int ac, char **av);

/*
 *	cheker.c
 */

int		cheker_sort(t_stack *stack);
int		cheker_sort_3a(t_stack *stack);

/*
 *	sort_2_and_3.c
 */

void	sort_2(t_stack *stack);
void	sort_3(t_stack *stack);

/*
 *	sort_all.c
 */

void	push_median(t_stack *stack);
void	sort_all(t_stack *stack);

/*
 *	main.c
 */

void	print_stack(t_stack *stack);
void	print_stack_b(t_stack *stack);
void	print_stack_a(t_stack *stack);

#endif