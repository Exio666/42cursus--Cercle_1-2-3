/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:16:07 by bsavinel          #+#    #+#             */
/*   Updated: 2021/12/05 18:14:11 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putnbr_base(long long int nbr, char *base)
{
	long long int	type;

	type = ft_strlen(base);
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= type)
	{
		ft_putnbr_base(nbr / type, base);
		nbr = nbr % type;
	}
	if (nbr < type)
		ft_putchar(base[nbr]);
}

void	ft_putnbr_unsign_base(unsigned long long int nbr, char *base)
{
	unsigned long long int	type;

	type = ft_strlen(base);
	if (nbr >= type)
	{
		ft_putnbr_unsign_base(nbr / type, base);
		nbr = nbr % type;
	}
	if (nbr < type)
		ft_putchar(base[nbr]);
}

int	ft_len_nbr(long long int n, char *base)
{
	int				i;
	long long int	type;
	
	i = 1;
	type = ft_strlen(base);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > type)
	{
		n = n / type;
		i++;
	}
	return (i);
}

int	ft_len_nbr_unsign(unsigned long long int n, char *base)
{
	int						i;
	unsigned long long int	type;
	
	i = 1;
	type = ft_strlen(base);
	while (n > type)
	{
		n = n / type;
		i++;
	}
	return (i);
}