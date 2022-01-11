/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:59:06 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/09 10:45:57 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strlen_test.h"

int	strlen_launcher(void)
{
	t_test_list	*list;

	list = init_test_list("STRLEN");
	add_test(list, "Basic test", &strlen_basic_test);
	add_test(list, "Null test", &strlen_null_test);
	return (launch_test(list));
}
