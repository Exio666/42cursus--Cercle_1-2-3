/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:26:49 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/18 15:29:44 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parse_map2(t_map *map, char *line, int j, int k)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]) == 1 || line[i] == '-')
		{
			set_3d_map(j, k, &line[i], map);
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
			set_3d_map(j, k, &line[i], map);
			k++;
		}
		while ((ft_isdigit(line[i]) || line[i] == '-') == 1 && line[i])
			i++;
	}
}

void	counter_line2(char *str, int ret, t_map *map, int first)
{
	int	i;

	i = 0;
	str[ret] = '\0';
	if (first == 0)
	{
		first = 1;
		map->min_z = ft_atoi(str);
		map->max_z = ft_atoi(str);
	}
	while (str[i])
	{
		if (str[i] == '\n')
			map->nb_line++;
		i++;
	}
	map->last_newline = 0;
	if (str[i - 1] == '\n')
		map->last_newline = 1;
}

void	exit_bug(t_map *map, char *line, int j)
{
	if (line)
		free(line);
	mlx_destroy_display(map->mlx_ptr);
	free(map->mlx_ptr);
	free_map3d(map, j);
	exit_prog(map, 5);
}
