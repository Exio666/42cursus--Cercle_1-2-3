/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 09:34:57 by bsavinel          #+#    #+#             */
/*   Updated: 2021/12/22 12:17:11 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h" 

static void ft_send_PID(int PID)
{
	int	i;
	int power2;

	
	i = 0;
	power2 = 1;
	while(i != 32)
	{
		if (PID % 2 == 1)
			kill(PID, 10);
		else
			kill(PID, 12);
		PID == PID / 2;
		pause();
		i++;
	}
}

int main(int argc, char **argv)
{
	int bin;
	int	i;
	int	j;
	int PID;
	
	i = 0;
	PID = ft_atoi(argv[1]);
	if (argc != 3)
		ft_printf("ERROR\n");
	else
	{
		ft_send_PID(getpid());
		while (argv[2][i])
		{
			bin = (int)argv[2][i];
			j = 1;
			while (j % 9 != 0)
			{
				if (bin % 2 == 1)
					kill(PID, 10);
				else
					kill(PID, 12);
				bin == bin / 2;
				pause();
				j++;
			}
			i++;
		}
	}
	return (0);
}
