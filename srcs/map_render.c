/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:50:05 by beefie            #+#    #+#             */
/*   Updated: 2025/04/02 20:17:51 by beefie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cubed.h"

static t_line	set_line(int *start, int *end)
{
	t_line	line;

	line.dx = abs(end[x] -start[x]);
	line.dy = abs(end[y] - start[y]);

	if (start[x] < end[x])
		line.sx = 1;
	else
		line.sx = -1;
	if (star[y] < end[y])
		line.sy = 1;
	else
		line.sy = -1;
	line.error = line.dx - line.dy;
	return (line);
}

void	draw_line(t_cubed
void	perpendicular(t_map *map)

