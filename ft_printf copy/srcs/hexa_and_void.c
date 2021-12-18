/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_and_void.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:01:42 by bsavinel          #+#    #+#             */
/*   Updated: 2021/12/18 16:26:31 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_xup(unsigned int nb, t_info *info)
{
	int		count;

	count = ft_len_nbr_unsign(nb, "0123456789ABCDEF");
	if (info->precision > count)
		count = info->precision;
	if (info->minus == FALSE && info->hastag == TRUE && nb != 0)
		count += ft_width(count + 2, info->width, info->zero);
	else if (info->minus == FALSE)
		count += ft_width(count, info->width, info->zero);
	if (info->hastag == TRUE && nb != 0)
	{
		ft_putstr_fd("0X", 1);
		count += 2;
	}
	ft_putnbr_unsign_base(nb, "0123456789ABCDEF");
	if (info->minus == TRUE)
		count += ft_width(count, info->width, FALSE);
	return (count);
}

int	ft_format_x(unsigned int nb, t_info *info)
{
	int		count;

	count = ft_len_nbr_unsign(nb, "0123456789abcdef");
	if (info->precision > count)
		count = info->precision;
	if (info->minus == FALSE && info->hastag == TRUE && nb != 0)
		count += ft_width(count + 2, info->width, info->zero);
	else if (info->minus == FALSE)
		count += ft_width(count, info->width, info->zero);
	if (info->hastag == TRUE && nb != 0)
	{
		ft_putstr_fd("0X", 1);
		count += 2;
	}
	ft_putnbr_unsign_base(nb, "0123456789abcdef");
	if (info->minus == TRUE)
		count += ft_width(count, info->width, FALSE);
	return (count);
}

int	ft_format_p(void *ad)
{
	int						count;
	char					*base;
	unsigned long long int	nb;

	if (!ad)
		return (ft_putstr_fd("0x0", 1));
	nb = (unsigned long long int)ad;
	base = "0123456789abcdef";
	count = ft_len_nbr_unsign(nb, base) + 2;
	write(1, "0x", 2);
	ft_putnbr_unsign_base(nb, base);
	return (count);
}
