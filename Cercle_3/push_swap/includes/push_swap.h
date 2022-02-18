/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 13:13:41 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/17 13:43:42 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "all_lib.h"
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
	int		*tab[3];
}	t_stack;

typedef struct s_choice
{
	int	choice;
	int	cost;
	int	nb_stack_a;
	int	nb_stack_b;
}	t_choice;

typedef struct s_option
{
	int			corespond;
	int			place[2];
	int			tab_cost[4];
	t_choice	choice;
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
void	free_tab(t_stack *stack, int nb, int chain, int cut);
void	malloc_stack(t_stack *stack, int ac);
void	ft_sort(int *tab, int i);
void	start(t_stack *stack, int ac, char **av);

/*
 *	cheker.c
 */

int		check_int(char *str);
int		cheker_sort(t_stack *stack);
int		cheker_sort_3a(t_stack *stack);
int		check_doublon(int *tab, int i, int nb);

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
int		clacul_choice(int place_a, int place_b);
int		proche(t_stack *stack);
void	push_under(t_stack *stack);

/*
 *	print_stack.c
 */

void	print_stack(t_stack *stack);
void	print_stack_b(t_stack *stack);
void	print_stack_a(t_stack *stack);

/*
 *	up_first.c
 */

void	ft_down_a(t_stack *stack);
void	ft_up_a(t_stack *stack);
void	up_first(t_stack *stack);

/*
 *	reinjection.c
 */

void	up_a_down_b(t_stack *stack, t_option *option, int size_b);
void	up_b_down_a(t_stack *stack, t_option *option, int size_a);
void	up_b_and_a(t_stack *stack, t_option *option);
void	down_b_and_a(t_stack *stack, t_option *option, int size_a, int size_b);
void	reinjection(t_stack *stack, t_option *option);

/*
 *	second_part.c
 */

int		find_most_lower(int nb, t_stack *stack, t_option *option);
void	feed_option(t_option *option, t_stack *stack);
void	second_part(t_stack *stack);
void	choice_the_choice(t_option *option, t_stack *stack, t_choice *test);

/*
 *	do_action.c
 */

int		do_action1(char *action, t_stack *stack);
int		do_action2(char *action, t_stack *stack);
int		do_action3(char *action, t_stack *stack);

#endif