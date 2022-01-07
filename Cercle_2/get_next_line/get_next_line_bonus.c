/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 08:36:14 by bsavinel          #+#    #+#             */
/*   Updated: 2021/12/06 13:34:50 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_joinstr(char *str, char *buf)
{
	char	*ret;

	if (str[0] == '\0')
	{
		ret = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!ret)
			return (NULL);
	}
	else
	{
		ret = malloc(sizeof(char) * (ft_strlen(str) + BUFFER_SIZE + 1));
		if (!ret)
			return (NULL);
	}
	ft_joinstr2(str, buf, ret);
	free(str);
	return (ret);
}

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

void	ft_replace(char *str)
{
	char	tmp[BUFFER_SIZE + 1];
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	i++;
	while (str[i])
	{
		tmp[j] = str[i];
		i++;
		j++;
	}
	ft_replace2(str, tmp, i, j);
}

char	*ft_line_return(char *str, char *tab)
{
	str = ft_joinstr(str, tab);
	ft_replace(tab);
	return (str);
}

char	*get_next_line(int fd)
{
	int			ret;
	char		*str;
	int			first;
	static char	tab[2048][BUFFER_SIZE + 1];

	if (fd < 0)
		return (NULL);
	str = malloc(sizeof(char) * 1);
	str[0] = '\0';
	first = 0;
	while (ft_new_line(tab[fd]) == 2 || first++ == 0)
	{
		if (ft_new_line(tab[fd]) != 1)
		{
			if (tab[fd][0] != '\0')
				str = ft_joinstr(str, tab[fd]);
			ft_bzero(tab[fd], BUFFER_SIZE);
			ret = read(fd, tab[fd], BUFFER_SIZE);
			tab[fd][ret] = '\0';
		}
	}
	str = ft_line_return(str, tab[fd]);
	if (str[0] == '\0')
		return (ft_end(str));
	return (str);
}
