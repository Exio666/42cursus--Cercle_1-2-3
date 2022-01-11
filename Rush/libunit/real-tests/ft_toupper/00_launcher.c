/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:58:58 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/09 14:14:38 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "toupper.h"

int	toupper_launcher(void)
{
	t_test_list	*list;

	list = init_test_list("ft_toupper");
	add_test(list, "From uppercase", &toupper_up_test);
	add_test(list, "From lowercase", &toupper_low_test);
	add_test(list, "Not a char", &toupper_notchar_test);
	return (launch_test(list));
}
