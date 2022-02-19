/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:45:46 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/19 18:12:42 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_3d_map(int j, int k, char *z, t_map *map)
{
	int	tmpz;

	map->map3d[j][k].x = k;
	map->map3d[j][k].y = j;
	tmpz = ft_atoi(z);
	map->map3d[j][k].z = tmpz;
	if (map->max_z < tmpz)
		map->max_z = tmpz;
	if (map->min_z > tmpz)
		map->min_z = tmpz;
}

int	len_line(char *str)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	if (!str)
		return (0);
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
	int		j;
	int		k;
	char	*line;

	j = 0;
	map->map3d = malloc(sizeof(t_3Dpoint *) * (map->nb_line + 1));
	if (!map->map3d)
		return (0);
	while (j != map->nb_line)
	{
		k = 0;
		line = get_next_line(fd);
		if (j == 0)
			map->len_line = len_line(line);
		if (map->len_line != len_line(line) || map->len_line <= 0 || !line)
			exit_bug(map, line, j);
		map->map3d[j] = malloc(sizeof(t_3Dpoint) * (map->len_line + 1));
		if (!map->map3d[j])
			return (free_map3d(map, j));
		parse_map2(map, line, j, k);
		free(line);
		j++;
	}
	return (1);
}

int	counter_line(int fd, t_map *map)
{
	char	str[1025];
	int		ret;
	int		first;

	ret = 1;
	map->nb_line = 0;
	first = 0;
	while (ret != 0)
	{
		ret = read(fd, str, 1024);
		if ((ret < 0) || (first == 0 && ret == 0))
			exit_prog(map, 5);
		else if (str[0] != ' ' && str[0] != '-' && ft_isdigit(str[0]) == 0
			&& first == 0)
			exit_prog(map, 5);
		else if (ret > 0)
			counter_line2(str, ret, map, first);
		first = 1;
	}
	if (map->last_newline == 0)
		map->nb_line++;
	return (1);
}

int	parser(char *file, t_map *map)
{
	int	fd;
	int	error;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_prog(map, 5);
	error = counter_line(fd, map);
	if (close(fd) == -1 || error == 0)
		exit_prog(map, 5);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_prog(map, 5);
	error = parse_map(fd, map);
	if (close(fd) == -1 || error == 0)
	{
		mlx_destroy_display(map->mlx_ptr);
		free(map->mlx_ptr);
		if (map->map3d)
			free_map3d(map, map->nb_line);
		exit(1);
	}
	return (1);
}
