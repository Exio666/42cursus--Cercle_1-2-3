/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:59:06 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/09 10:46:20 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "atoi_test.h"

int	atoi_launcher(void)
{
	t_test_list	*list;

	list = init_test_list("ATOI");
	add_test(list, "Basic test", &atoi_basic_test);
	add_test(list, "Plus test", &atoi_plus_test);
	return (launch_test(list));
}
