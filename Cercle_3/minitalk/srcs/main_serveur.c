/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_serveur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 10:17:03 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/04 17:41:10 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h" 
#include <stdio.h>

t_talk	g_talk;

void	ft_treat_signal(int signal)
{
	if (signal == 12)
		g_talk.bit = 1;
	else
		g_talk.bit = 0;
	g_talk.size++;
}

void	ft_flush_talk(void)
{
	g_talk.bit = 0;
	g_talk.size = 0;
	g_talk.num = 0;
	g_talk.end = 0;
}

static void	ft_recive_pid(void)
{
	g_talk.power2 = 1;
	while (g_talk.size != 24)
	{
		pause();
		signal(10, ft_treat_signal);
		signal(12, ft_treat_signal);
		if (g_talk.bit == 1)
			g_talk.PID += g_talk.power2;
		g_talk.power2 *= 2;
		g_talk.size++;
	}
}

static void	ft_recive_char(void)
{
	g_talk.power2 = 1;
	while (g_talk.size != 8)
	{
		pause();
		signal(10, ft_treat_signal);
		signal(12, ft_treat_signal);
		if (g_talk.bit == 1)
			g_talk.num += g_talk.power2;
		g_talk.power2 *= 2;
		g_talk.size++;
	}
}

int	main(void)
{
	ft_putnbr(getpid());
	while (1)
	{
		ft_flush_talk();
		g_talk.PID = 0;
		ft_recive_pid();
		while (g_talk.end == 0)
		{
			ft_flush_talk();
			if (g_talk.num != 0)
				ft_putchar_fd(g_talk.num, 1);
			else
				g_talk.end = 1;
		}
	}
	return (0);
}
