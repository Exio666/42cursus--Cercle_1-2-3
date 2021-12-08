/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_and_void.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:01:42 by bsavinel          #+#    #+#             */
/*   Updated: 2021/12/08 10:06:59 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_xup(unsigned int nb, int *tab)
{
	int		count;
	char	*base;
	int		i;

	i = 0;
	if (tab[35] == 1 && nb != 0)
	{
		ft_putstr("0X");
		i = i + 2;
	}
	base = "0123456789ABCDEF";
	count = ft_len_nbr_unsign(nb, base) + i;
	ft_putnbr_unsign_base(nb, base);
	return (count);
}

int	ft_format_x(unsigned int nb, int *tab)
{
	int		count;
	char	*base;
	int		i;

	i = 0;
	if (tab[35] == 1 && nb != 0)
	{
		ft_putstr("0x");
		i = i + 2;
	}
	base = "0123456789abcdef";
	count = ft_len_nbr_unsign(nb, base) + i;
	ft_putnbr_unsign_base(nb, base);
	return (count);
}

int	ft_format_p(void *ad)
{
	int						count;
	char					*base;
	unsigned long long int	nb;

	if (!ad)
		return (ft_putstr("0x0"));
	nb = (unsigned long long int)ad;
	base = "0123456789abcdef";
	count = ft_len_nbr_unsign(nb, base) + 2;
	write(1, "0x", 2);
	ft_putnbr_unsign_base(nb, base);
	return (count);
}
