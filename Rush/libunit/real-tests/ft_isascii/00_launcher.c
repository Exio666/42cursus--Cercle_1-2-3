/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:58:58 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/09 14:15:50 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "isascii.h"

int	isascii_launcher(void)
{
	t_test_list	*list;

	list = init_test_list("ft_isascii");
	add_test(list, "Yes", &isascii_yes);
	add_test(list, "No", &isascii_no);
	return (launch_test(list));
}
