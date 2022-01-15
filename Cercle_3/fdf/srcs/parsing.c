/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:45:46 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/15 13:36:44 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	len_line(char *str)
{
	int i;
	int counter;

	i = 0;
	while (str[i])
	{
		while (ft_isdigit(str[i]) == 1)
			i++;
		counter++;
		i++;
	}
	return(counter);
}

int **parser(char *file)
{
	int	fd;
	char *line;
	char **tab;
	int **map;
	int i;
	int len;
	int j;

	i = 0;
	j = 0;
	fd = open(file, O_RDONLY);
	if (!fd)
		return(NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (map);
		if (j = 0)
			len = len_line(line);
		tab = ft_split(line, ' ');
		free(line);
		if (!tab)
			return (NULL);
		while(tab[i])
		{
			map[j][i] = ft_atoi(tab[i]);
			free(tab[i]);
			i++;
		}
		free(tab);
		j++;
	}
	close(fd);
	map[j] = NULL;
	return (map);
}