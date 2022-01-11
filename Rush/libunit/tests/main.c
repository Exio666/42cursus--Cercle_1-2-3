/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 09:33:59 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/09 09:53:17 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "launcher.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 1;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

void	timeout_function(void)
{
	while (1)
		;
}

void	bus_function(void)
{
	char	*p;
	int		i;

	asm("pushf\n\torl $0x40000,(%rsp)\n\tpopf");
	p = malloc(sizeof(int) + 1);
	p++;
	i = *(int *)p;
	(void)i;
}

int	main(void)
{
	strlen_launcher();
	atoi_launcher();
	bug_launcher();
}
