/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:06:23 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/07 11:22:02 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	select_hook(int hook, t_map *map)
{
	if (hook == D_ESCAPE)
		exit_prog2(map);
	else if (hook == D_ROT_UPZ)
		map->rot_z += ROTATION;
	else if (hook == D_ROT_DOWNZ)
		map->rot_z -= ROTATION;
	else if (hook == D_ROT_UPX)
		map->rot_x += ROTATION;
	else if (hook == D_ROT_DOWNX)
		map->rot_x -= ROTATION;
	else if (hook == D_ROT_UPY)
		map->rot_y += ROTATION;
	else if (hook == D_ROT_DOWNY)
		map->rot_y -= ROTATION;
	else if (hook == D_TRANS_UP)
		map->translation_y -= TRANSLATION;
	else if (hook == D_TRANS_DOWN)
		map->translation_y += TRANSLATION;
	else
		select_hook2(hook, map);
	print_map(map);
	return (1);
}

void	select_hook2(int hook, t_map *map)
{
	if (hook == D_TRANS_LEFT)
		map->translation_x -= TRANSLATION;
	else if (hook == D_TRANS_RIGHT)
		map->translation_x += TRANSLATION;
	else if (hook == D_UP_ZOOM)
		map->zoom = map->zoom * V_ZOOM;
	else if (hook == D_DOWN_ZOOM)
		map->zoom = map->zoom / V_ZOOM;
	else if (hook == D_RESET)
		reset_map(map);
	else if (hook == D_PROJECTION)
		map->projection += 1;
}
