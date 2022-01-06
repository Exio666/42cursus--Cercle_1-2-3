/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 10:17:03 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/06 15:53:10 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h" 
#include <stdio.h>

t_talk	g_talk;

void	ft_treat_signal(int signal, siginfo_t *sa, void *vp)
{
	(void) vp;
	g_talk.ready = 1;
	g_talk.pid = sa->si_pid;
	if (signal == 10)
		g_talk.bit = 0;
	else if (signal == 12)
		g_talk.bit = 1;
}

void	ft_flush_talk(void)
{
	g_talk.num = 0;
	g_talk.power2 = 128;
}

static void	ft_recive_char(void)
{
	ft_flush_talk();
	while (g_talk.power2 != 0)
	{		
		while (g_talk.ready == 0)
			;
		g_talk.ready = 0;
		if (g_talk.bit == 1)
			g_talk.num += g_talk.power2;
		g_talk.power2 = g_talk.power2 / 2;
		if (kill(g_talk.pid, 10) == -1)
		{
			g_talk.debug = 1;
			break ;
		}
	}
}

unsigned char	*ft_realloc(unsigned char *str1, int i)
{
	unsigned char	*str2;
	int				j;

	j = 0;
	str2 = malloc (sizeof(unsigned char) * (i + 1));
	while (j < i)
	{
		str2[j] = str1[j];
		j++;
	}
	if (i != 0)
		free(str1);
	return (str2);
}

void	ft_start_minitalk(void)
{
	struct sigaction	sa;
	
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_treat_signal;
	g_talk.debug = 0;
	sigaction(10, &sa, NULL);
	sigaction(12, &sa, NULL);
	ft_putstr_fd("Welcome user, I write messages send to the PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n        =======================================\n\n", 1);
}

int	main(void)
{
	unsigned char	*str;
	int				i;
	
	ft_start_minitalk();
	while (1)
	{
		i = 0;
		g_talk.ready = 0;
		g_talk.num = 1;
		while (g_talk.num != 0)
		{
			ft_flush_talk();
			str = ft_realloc(str, i);
			ft_recive_char();
			if (g_talk.debug == 1)
			{
				ft_putstr_fd("Very bad probleme, please relaunch", 1);
				free(str);
				exit(1);
			}
			str[i] = (unsigned char)g_talk.num;
			i++;
		}
		ft_putstr_unsigned_fd(str, 1);
		free(str);
		ft_putstr_fd("\n\nReady for next message\n\n", 1);
	}
	return (0);
}
