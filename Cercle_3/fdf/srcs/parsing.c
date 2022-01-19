/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:45:46 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/19 12:13:53 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_3Dpoint	set_3d_map(int x, int y, char *z)
{
	t_3Dpoint	p;

	p.x = x;
	p.y = y;
	p.z = ft_atoi(z);
	return (p);
}

int	len_line(char *str)
{
	int		i;
	int		counter;
	char	**tab;

	i = 0;
	counter = 0;
	tab = ft_split(str, ' ');
	while (tab[i])
	{
		counter++;
		free(tab[i]);
		i++;
	}
	free(tab);
	return (counter);
}

int	parse_map(int fd, t_map *map)
{
	int		i;
	int		j;
	char	*line;
	char	**tab;

	j = 0;
	map->map3d = malloc(sizeof(t_3Dpoint *) * (map->nb_line + 1));
	if (!map->map3d)
		return (0);
	while (j != map->nb_line)
	{
		i = 0;
		line = get_next_line(fd);
		if (j == 0)
			map->len_line = len_line(line);
		map->map3d[j] = malloc(sizeof(t_3Dpoint) * (map->len_line + 1));
		if (!map->map3d[j])
			return (free_map(map->map3d));
		tab = ft_split(line, ' ');
		free(line);
		if (!tab)
			return (0);
		while (tab[i])
		{
			map->map3d[j][i] = set_3d_map(j, i, tab[i]);
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
