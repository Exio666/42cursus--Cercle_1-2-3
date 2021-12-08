/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:43:20 by bsavinel          #+#    #+#             */
/*   Updated: 2021/12/08 10:10:12 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**** Tablau des flag *****
 **** tab[0]   =>  i  *****	[X]
 **** tab[35]  =>  #  *****	[X]
 **** tab[32]  => ' ' *****	[X]
 **** tab[43]  =>  +  *****	[X]
 **************************/

/**************************
{#} for x print "0x"
	for X print "0X"
{+} positive number start with +
{ } positive number start with ' '
	no effect with {+}
***************************/

int	ft_is_flag(char c)
{
	char	*str;
	int		i;

	i = 0;
	str = "xuXdpisc%";
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_tab_flag(char *str, int *tab)
{
	char	*mod;
	int		i;

	i = 0;
	mod = "# +";
	while (mod[i])
	{
		tab[(int)mod[i]] = 0;
		i++;
	}
	i = 0;
	while (ft_is_flag(str[i]) == 0)
	{
		tab[(int)str[i]] = 1;
		i++;
	}
	tab[0] = i;
}
