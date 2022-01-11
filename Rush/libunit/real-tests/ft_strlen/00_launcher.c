/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:58:58 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/09 14:16:49 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strlen.h"

int	strlen_launcher(void)
{
	t_test_list	*list;

	list = init_test_list("ft_strlen");
	add_test(list, "Classic string", &strlen_longstr_test);
	add_test(list, "Null string ", &strlen_nullstr_test);
	add_test(list, "Empty string", &strlen_emptystr_test);
	return (launch_test(list));
}
