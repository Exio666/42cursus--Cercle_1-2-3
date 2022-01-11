/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:21:16 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/09 14:28:28 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atoi.h"

int	atoi_launcher(void)
{
	t_test_list	*list;

	list = init_test_list("ft_atoi");
	add_test(list, "0", &atoi_0);
	add_test(list, "Positive", &atoi_positive);
	add_test(list, "Negative", &atoi_negative);
	add_test(list, "Int min", &atoi_intmin);
	add_test(list, "Int max", &atoi_intmax);
	add_test(list, "Overflow", &atoi_overflow);
	add_test(list, "With +", &atoi_plus);
	add_test(list, "With + and -", &atoi_plus_minus);
	add_test(list, "With white spaces", &atoi_whitespaces);
	return (launch_test(list));
}
