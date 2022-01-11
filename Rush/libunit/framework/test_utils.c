/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:28:58 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/08 14:01:21 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

t_test_list	*init_test_list(char *tested_function_name)
{	
	t_test_list	*test_list;

	test_list = malloc(sizeof(t_test_list));
	if (!test_list)
		return (NULL);
	test_list->function_name = tested_function_name;
	test_list->test = NULL;
	return (test_list);
}

static t_test	*create_test(char *test_name, int (*ft_test)(void))
{
	t_test	*test_elem;

	test_elem = malloc(sizeof(t_test));
	if (!test_elem)
		return (NULL);
	test_elem->test_name = test_name;
	test_elem->test = ft_test;
	test_elem->next_test = NULL;
	return (test_elem);
}

t_test_list	*free_test_list(t_test_list *test_list)
{
	t_test	*elem;
	t_test	*tmp;

	if (test_list->test != NULL)
	{
		elem = test_list->test;
		while (elem != NULL)
		{
			tmp = elem->next_test;
			free(elem);
			elem = tmp;
		}
	}
	free(test_list);
	return (NULL);
}

t_test_list	*add_test(t_test_list *test_list,
	char *test_name, int (*ft_test)(void))
{
	t_test	*elem;

	if (test_list == NULL)
		return (NULL);
	if (test_list->test == NULL)
	{
		test_list->test = create_test(test_name, ft_test);
		if (!(test_list->test))
			return (free_test_list(test_list));
	}
	else
	{
		elem = test_list->test;
		while (elem->next_test != NULL)
			elem = elem->next_test;
		elem->next_test = create_test(test_name, ft_test);
		if (!(elem->next_test))
			return (free_test_list(test_list));
	}
	return (test_list);
}
