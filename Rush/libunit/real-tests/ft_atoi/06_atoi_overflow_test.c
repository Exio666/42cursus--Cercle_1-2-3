/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_atoi_overflow_test.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:25:55 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/09 14:57:23 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atoi.h"

//Test overflow, undefined behavior but need to not crash
int	atoi_overflow(void)
{
	ft_atoi("214748364765");
	return (0);
}
