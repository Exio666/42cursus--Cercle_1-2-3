/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:26:49 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/31 16:39:52 by bsavinel         ###   ########.fr       */
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
}
