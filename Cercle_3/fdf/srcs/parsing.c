/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:45:46 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/25 14:15:04 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_3Dpoint	set_3d_map(int y, int x, char *z)
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

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1 || str[i] == '-')
			counter++;
		while ((ft_isdigit(str[i]) == 1 || str[i] == '-' ) && str[i])
			i++;
		while (str[i] != ' ' && str[i])
			i++;
		if (str[i] == ' ')
			i++;
		if (ft_isdigit(str[i]) == 1 || str[i] == '-')
			counter++;
		while ((ft_isdigit(str[i]) || str[i] == '-') == 1 && str[i])
			i++;
	}
	return (counter);
}

int	parse_map(int fd, t_map *map)
{
	int		i;
	int		j;
	int		k;
	char	*line;

	j = 0;
	map->map3d = malloc(sizeof(t_3Dpoint *) * (map->nb_line + 1));
	if (!map->map3d)
		return (0);
	while (j != map->nb_line)
	{
		i = 0;
		k = 0;
		line = get_next_line(fd);
		if (j == 0)
			map->len_line = len_line(line);
		map->map3d[j] = malloc(sizeof(t_3Dpoint) * (map->len_line + 1));
		if (!map->map3d[j])
			return (free_map3d(map, j));
		while (line[i])
		{
			if (ft_isdigit(line[i]) == 1 || line[i] == '-')
			{
				map->map3d[j][k] = set_3d_map(j, k, &line[i]);
				k++;
			}
			while ((ft_isdigit(line[i]) == 1 || line[i] == '-' ) && line[i])
				i++;
			while (line[i] != ' ' && line[i])
				i++;
			if (line[i] == ' ')
				i++;
			if (ft_isdigit(line[i]) == 1 || line[i] == '-')
			{
				map->map3d[j][k] = set_3d_map(j, k, &line[i]);
				k++;
			}
			while ((ft_isdigit(line[i]) || line[i] == '-') == 1 && line[i])
				i++;
		}
		free(line);
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
			free_map3d(map, map->nb_line);
		return (0);
	}
	return (1);
}
