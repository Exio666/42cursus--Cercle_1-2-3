/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_serveur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 10:17:03 by bsavinel          #+#    #+#             */
/*   Updated: 2021/12/22 12:21:01 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h" 
#include <stdio.h>

static int	ft_recive_PID()
{
	int	PID;
	int	i;
	int power2;

	
	i = 0;
	power2 = 1;
	while(i != 32)
	{
		if (/*resoie sig2*/)
			bin = bin + power2;
		power2 = power2 * 2;
		i++;
		pause();
	}
}

int main()
{
	int	bin;
	int	j;
	int power2;
	int PID;
	
	i = 0;
	ft_printf("%i\n", getpid());
	pause();
	PID = ft_recive_PID();
	while (i != 1)
	{
		pause();
		j = 1
		power2 = 1;
		bin = 0;
		while(j % 9 != 0)
		{
			if (/*resoie sig2*/)
				bin = bin + power2;
			power2 = power2 * 2;
			j++;
		}
		ft_putchar_fd(bin, 1);
		kill(PID,10);
	}
	return (0);
}
