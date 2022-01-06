/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 09:34:57 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/06 17:21:15 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h" 

t_talk	g_client;

static void	ft_send_char(int pid, int car)
{
	int	x;

	x = 0;
	g_client.power2 = 128;
	while (g_client.power2 != 0 && g_client.debug != 1)
	{
		while (g_client.ready == 0 || x < 10000)
			x++;
		g_client.ready = 0;
		if (car >= g_client.power2)
		{
			car = car - g_client.power2;
			x = kill(pid, 12);
		}
		else
			x = kill(pid, 10);
		g_client.power2 = g_client.power2 / 2;
		if (x == -1)
			g_client.debug = 1;
	}
}

void	ft_signal(int signal)
{
	if (signal == 10)
		g_client.ready = 1;
}

int	main(int argc, char **argv)
{
	int	i;
	int	len;
	int	pid;

	g_client.debug = 0;
	i = 0;
	pid = ft_atoi(argv[1]);
	g_client.ready = 1;
	signal(10, &ft_signal);
	if (argc != 3)
		ft_putstr_fd("Bad number of argument", 1);
	else
	{
		len = ft_unsigned_strlen((unsigned char *)argv[2]);
		while (i <= len)
		{
			ft_send_char(pid, (unsigned char)argv[2][i]);
			if (g_client.debug == 1)
			{
				ft_putstr_fd("Transmition failed. Probably a PID mystake", 1);
				exit(1);
			}
			i++;
		}
	}
	return (0);
}
