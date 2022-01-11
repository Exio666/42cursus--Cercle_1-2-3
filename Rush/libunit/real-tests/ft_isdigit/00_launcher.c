/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:58:58 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/09 14:07:39 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "isdigit.h"

int	isdigit_launcher(void)
{
	t_test_list	*list;

	list = init_test_list("ft_isdigit");
	add_test(list, "0", &isdigit_0);
	add_test(list, "No", &isdigit_no);
	add_test(list, "9", &isdigit_9);
	return (launch_test(list));
}
