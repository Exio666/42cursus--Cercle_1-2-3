/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 08:36:11 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/01 16:15:27 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*byte;

	i = 0;
	byte = (unsigned char *) s;
	while (i < n)
	{
		byte[i] = 0;
		i++;
	}
}

void	ft_joinstr2(char *str, char *buf, char *ret)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	while (buf[j] && buf[j] != '\n')
	{
		ret[i] = buf[j];
		i++;
		j++;
	}
	if (buf[j] == '\n')
	{
		ret[i] = '\n';
		i++;
		j++;
	}
	ret[i] = '\0';
}

void	ft_replace2(char *str, char *tmp, int i, int j)
{
	tmp [j] = '\0';
	i = 0;
	while (tmp[i])
	{
		str[i] = tmp[i];
		i++;
	}
	while (i <= BUFFER_SIZE)
	{
		str[i] = '\0';
		i++;
	}
}

char	*ft_end(char *str)
{
	if (str[0] == '\0')
	{
		free(str);
		return (NULL);
	}
	return (str);
}
