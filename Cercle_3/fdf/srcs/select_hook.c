/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:06:23 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/18 17:08:57 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	select_hook(int hook, t_map *map)
{
	if (hook == D_ESCAPE)
		;
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
		translat_vertical(map, TRANSLATION);
	else if (hook == D_TRANS_DOWN)
		translat_vertical(map, -TRANSLATION);
	else if (hook == D_TRANS_LEFT)
		translat_horizontal(map, TRANSLATION);
	else if (hook == D_TRANS_RIGHT)
		translat_horizontal(map, -TRANSLATION);
	else
		select_hook2(hook,map);
}

void	select_hook2(int hook, t_map *map)
{
	if (hook == D_UP_ZOOM)
		;	
	else if (hook == D_DOWN_ZOOM)
		;
	else if (hook == D_COLOR)
		;
	else if (hook == D_RESET)
		;
	else if (hook == D_ISOMETRIC)
		;
	else if (hook == D_PARALLEL)
		;
}