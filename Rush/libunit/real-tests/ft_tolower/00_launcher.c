/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:58:58 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/09 14:12:33 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tolower.h"

int	tolower_launcher(void)
{
	t_test_list	*list;

	list = init_test_list("ft_tolower");
	add_test(list, "From upcase", &tolower_up_test);
	add_test(list, "From lowcase", &tolower_low_test);
	add_test(list, "Not a char", &tolower_notchar_test);
	return (launch_test(list));
}
