/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:25:54 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/06 14:52:57 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int))
{
	t_list	*begin;
	t_list	*index_lst;
	t_list	*new_elem;

	begin = NULL;
	index_lst = lst;
	while (index_lst)
	{
		new_elem = ft_lstnew(f(index_lst->content));
		if (!new_elem)
		{
			ft_lstclear(&begin);
			return (NULL);
		}
		index_lst = index_lst->next;
		ft_lstadd_back(&begin, new_elem);
	}
	return (begin);
}
