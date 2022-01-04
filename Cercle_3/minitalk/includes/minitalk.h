/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 09:35:23 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/04 15:52:29 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>

typedef struct s_talk
{
	int bit;
	int size;
	int power2;
	int num;
	int end;
	int PID;
}	t_talk;


int	ft_putchar_fd(char c, int fd);
int	ft_atoi(const char *nptr);

#endif
