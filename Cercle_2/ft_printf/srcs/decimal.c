/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:47:18 by bsavinel          #+#    #+#             */
/*   Updated: 2021/12/08 09:57:40 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_d(int nb, int *tab)
{
	int		count;
	char	*base;
	int		i;

	i = 0;
	if (tab[43] == 1 && nb >= 0)
	{
		ft_putstr("+");
		i = i + 1;
		tab[32] = 0;
	}
	if (tab[32] == 1 && nb >= 0)
	{
		ft_putstr(" ");
		i = i + 1;
	}
	base = "0123456789";
	count = ft_len_nbr(nb, base) + i;
	ft_putnbr_base(nb, base);
	return (count);
}

int	ft_format_u(unsigned int nb)
{
	int		count;
	char	*base;

	base = "0123456789";
	count = ft_len_nbr_unsign(nb, base);
	ft_putnbr_unsign_base(nb, base);
	return (count);
}