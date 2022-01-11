/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:59:06 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/09 11:52:14 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bug_test.h"

int	bug_launcher(void)
{
	t_test_list	*list;

	list = init_test_list("BUGS");
	add_test(list, "Timeout", &timeout_test);
	add_test(list, "Bus", &bus_test);
	add_test(list, "sigfpe", &sigfpe_test);
	add_test(list, "sigpipe", &sigpipe_test);
	add_test(list, "sigill", &sigill_test);
	add_test(list, "sigabrt", &sigabrt_test);
	return (launch_test(list));
}
