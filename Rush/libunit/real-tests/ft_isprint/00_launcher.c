/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:58:58 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/09 14:10:12 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "isprint.h"

int	isprint_launcher(void)
{
	t_test_list	*list;

	list = init_test_list("ft_isprint");
	add_test(list, "Yes", &isprint_yes);
	add_test(list, "No", &isprint_no);
	add_test(list, "Inf limit", &isprint_limitinf);
	add_test(list, "Sup limit", &isprint_limitsup);
	return (launch_test(list));
}
