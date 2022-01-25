/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:06:23 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/25 16:52:01 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	select_hook(int hook, t_map *map)
{
	if (hook == D_ESCAPE)
		exit_prog(map, 0);
	else if (hook == D_ROT_UPZ)
		apply_rotate(map, ROTATION, 0, 0);
	else if (hook == D_ROT_DOWNZ)
		apply_rotate(map, -ROTATION, 0, 0);
	else if (hook == D_ROT_UPX)
		apply_rotate(map, 0, 0, ROTATION);
	else if (hook == D_ROT_DOWNX)
		apply_rotate(map, 0, 0, -ROTATION);
	else if (hook == D_ROT_UPY)
		apply_rotate(map, 0, ROTATION, 0);
	else if (hook == D_ROT_DOWNY)
		apply_rotate(map, 0, -ROTATION, 0);
	else if (hook == D_TRANS_UP)
		map->translation_y -= TRANSLATION;
	else if (hook == D_TRANS_DOWN)
		map->translation_y += TRANSLATION;
	else if (hook == D_TRANS_LEFT)
		map->translation_x -= TRANSLATION;
	else if (hook == D_TRANS_RIGHT)
		map->translation_x += TRANSLATION;
	else
		select_hook2(hook, map);
	print_map(map);
	return (1);
}

void	select_hook2(int hook, t_map *map)
{
	if (hook == D_UP_ZOOM)
		map->zoom += V_ZOOM;
	else if (hook == D_DOWN_ZOOM)
		map->zoom -= V_ZOOM;
	else if (hook == D_COLOR)
		map->zoom -= V_ZOOM;
	else if (hook == D_RESET)
		map->zoom -= V_ZOOM;
	else if (hook == D_ISOMETRIC)
		map->zoom -= V_ZOOM;
	else if (hook == D_PARALLEL)
		map->zoom -= V_ZOOM;
}
