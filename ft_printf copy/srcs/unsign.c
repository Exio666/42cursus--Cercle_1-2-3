/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsign.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:32:37 by bsavinel          #+#    #+#             */
/*   Updated: 2021/12/20 15:57:49 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_format_u(unsigned int nb, t_info *info)
{
	int		count;
	int 	len;

	count = 0;
	if (!(nb == 0 && info->precision == 0))
		count = ft_len_nbr_unsign(nb, "0123456789");
	len = count;
	if (count < info->precision)
		count = info->precision;
	if (info->minus == FALSE && info->precision != 0)
		count += ft_width(count, info->width, info->zero);
	else if (info->minus == FALSE)
		count += ft_width(count, info->width, FALSE);
	while (len < info->precision)
	{
		ft_putchar_fd('0', 1);
		info->precision--;
	}
	if (!(nb == 0 && info->precision == 0))
		ft_putnbr_unsign_base(nb, "0123456789");
	if (info->minus == TRUE)
		count += ft_width(count, info->width, FALSE);
	return (count);
}
