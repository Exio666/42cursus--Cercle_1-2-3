/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:45:46 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/16 13:30:05 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void free_map(int **map)
{
	int i;
	
	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
}

int len_line(char *str)
{
	int i;
	int counter;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			counter++;
		i++;
	}
	return (counter);
}

int	parse_map(int fd, t_map *map)
{
	int	i;
	int	j;
	char *line;
	char **tab;

	j = 0;
	map->map3d = malloc(sizeof(int *) * (map->nb_line + 1));
	if (map->map3d)
		return (0);
	while (j != map->nb_line)
	{
		i = 0;
		line = get_next_line(fd);
		if (j == 0)
			map->len_line = len_line(line);
		map->map3d[j] = malloc(sizeof(int) * (map->len_line + 1));
		if (!map->map3d[j])
		{
			free_map(map->map3d);
			return (0);
		}
		tab = ft_split(line, ' ');
		free(line);
		if (!tab)
			return (0);
		while (tab[i])
		{
			map->map3d[j][i] = ft_atoi(tab[i]);
			free(tab[i]);
			i++;
		}
		free(tab);
		j++;
	}
	return (1);
}

int	counter_line(int fd, t_map *map)
{
	char	str[1001];
	int		i;
	int		ret;

	ret = 1;
	map->nb_line = 0;
	while (ret != 0)
	{
		i = 0;
		ret = read(fd, str, 1000);
		str[ret] = '\0';
		while (str[i])
		{
			if (str[i] == '\n')
				map->nb_line++;
			i++;
		}
	}
	return (1);
}

int	parser(char *file, t_map *map)
{
	int	fd;
	int	error;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	error = counter_line(fd, map);
	if (close(fd) == -1 || error == 0)
		return (0);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	error = parse_map(fd, map);
	if (close(fd) == -1 || error == 0)
	{
		if (map)
			free_map(map->map3d);
		return (0);
	}
	return (1);
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
