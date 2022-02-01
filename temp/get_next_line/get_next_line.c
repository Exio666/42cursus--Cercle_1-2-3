/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:55:28 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/01 16:11:32 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_new_line(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (2);
}

char	new_static(char *str, int ret)
{
	int		i;
	int		j;
	char	tmp[BUFFER_SIZE + 1];
	
	i = 0;
	j = 0;
	while (str[i] != '\n' && i < ret)
		i++;
	while (i < ret)
	{
		
	}
	return (new);
}

int finder(char *str, int first, int ret)
{
	int i;

	if (first = 0)
		return (1);
	i = 0;
	while (i < ret)
	{
		if (tab[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	**get_next_line(int fd)
{
	int			ret;
	char		*str;
	int			i;
	int			j;
	static char tab[2048][BUFFER_SIZE + 1];

	ret = 1;
	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	while (ret > 0 && finder(tab[fd], i, ret))
	{
		j = 0;
		ret = read(fd, tab[fd], BUFFER_SIZE);
		tab[fd][ret] = '\0';
		while (j < ret && tab[fd][j] != '\n')
		{
			str[i] = tab[fd][j];
			j++;
			i++;
		}
	}
	tab[fd] = new_static(tab[fd], ret);
	return (str);	
}