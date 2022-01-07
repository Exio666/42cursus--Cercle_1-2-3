/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_server.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 08:53:33 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/07 08:59:24 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_bug_server(unsigned char	*str)
{
	ft_putstr_fd("Very bad probleme, please relaunch", 1);
	free(str);
	exit(1);
}
