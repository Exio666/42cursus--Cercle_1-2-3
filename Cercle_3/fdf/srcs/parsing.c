/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:45:46 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/15 17:10:07 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int len_line(char *str)
{
	int i;
	int counter;

	i = 0;
	while (str[i])
	{
		if (str[i] = ' ')
			counter++;
		i++;
	}
	return (counter);
}

int	**parse_map(int fd, int nb_line)
{
	int **map;
	int	i;
	int	j;
	char *line;
	int len;
	char **tab;

	j = 0;
	map = malloc(sizeof(int *) * (nb_line + 1));
	if (!map)
		return (NULL);
	while (j != nb_line)
	{
		i = 0;
		line = get_next_line(fd);
		if (j == 0)
			len = len_line(line);
		map[j] = malloc(sizeof(int) * (len + 1));
		tab = ft_split(line, ' ');
		free(line);
		if (!tab)
			return (NULL);
		while (tab[i])
		{
			map[j][i] = ft_atoi(tab[i]);
			free(tab[i]);
			i++;
		}
		map[j][i] = NULL;
		free(tab);
		j++;
	}
	map[j] = NULL;
	return (map);
}

int	counter_line(int fd)
{
	int		counter;
	char	*str[1001];
	int		i;
	int		ret;

	ret = 1;
	counter = 1;
	while (ret != 0)
	{
		i = 0;
		ret = read(fd, str, 1000);
		str[ret] = '\0';
		while (str[i])
		{
			if (str[i] == '\n')
				counter++;
			i++;
		}
	}
	return (counter);
}

int	**parser(char *file)
{
	int			fd;
	int 		nb_line;
	int			**map;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (NULL);
	nb_line = counter_line(fd);
	if (close(fd) == -1)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (!fd)
		return (NULL);
	map = parse_map(fd, nb_line);
	if (close(fd) == -1)
	{
		if (map)
			free_map(map);
		return (NULL)
	}
	return (map);
}
	
/*
	
	char		*line;
	char		**tab;
	int			**map;
	int			i;
	int			len;
	
	
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (map);
		if (j == 0)
			len = len_line(line);
		tab = ft_split(line, ' ');
		free(line);
		if (!tab)
			return (NULL);
		while (tab[i])
		{
			map[j][i] = ft_atoi(tab[i]);
			free(tab[i]);
			i++;
		}
		map[j][i] = NULL;
		free(tab);
		j++;
	}
	close(fd);
	map[j] = NULL;
	return (map);
*/
