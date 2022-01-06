/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 09:35:23 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/06 17:20:21 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include "libft.h"

typedef struct s_talk
{
	int	debug;
	int	bit;
	int	power2;
	int	num;
	int	pid;
	int	ready;
}	t_talk;

#endif
