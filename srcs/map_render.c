/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:50:05 by beefie            #+#    #+#             */
/*   Updated: 2025/04/03 14:33:45 by beefie           ###   ########.fr       */
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
//ripped someones bresenham algo implementation
//claculates best pixel to draw lines with
void	draw_line(t_image *img int *start, int *end int colour)
{
	t_line	line;
	int	x0;
	int	y0;
	int	e2;

	x0 = start[x];
	y0 = start[y];
	line = set_values(start, end);
	while (x0 != end[x] || y0 != end[y])
	{
		set_pix(img, x0, y0, colour);
		e2 = 2 * line.err;
		if  (e2 > -line.dy)
		{
			line.err -= line.dy;
			x0 += line.sx;
		}
		if (e2 < line.dx)
		{
			line.err += line.dx;
			y0 += line.sy;
		}
	}
}

}
void	perpendicular(t_map *map)

