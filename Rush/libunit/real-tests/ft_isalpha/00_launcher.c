/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:58:58 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/09 14:02:35 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "isalpha.h"

int	isalpha_launcher(void)
{
	t_test_list	*list;

	list = init_test_list("ft_isalpha");
	add_test(list, "Yes cap", &isalpha_yes_cap);
	add_test(list, "Yes no cap", &isalpha_yes_cap);
	add_test(list, "No", &isalpha_no);
	return (launch_test(list));
}
