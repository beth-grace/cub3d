/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:50:05 by beefie            #+#    #+#             */
/*   Updated: 2025/04/03 22:08:55 by beefie           ###   ########.fr       */
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
static void	perpendicular(t_map *map)
//dda algo
static void calc_step(t_player *player)
{
	if (player->raydir[x] < 0)
	{
		player->step[x] = -1;
		player->sidedist[x] = (player->player[x] - player->map->map[x])
			* player->deltadist[x];
	}
	else
	{
		player->step[x] = 1;
		player->sidedist[x] = (player->map->map[x] + 1.0 - player->player[x])
			* player->deltadist[x];
	}
	if (player->raydir[y] < 0)
	{
		player->step[y] = -1;
		player->sidedist[y] = (player->player[y] - player->map->&map[y])
			* player->deltadist[y];
	}
	else
	{
		player->step[y] = 1;
		player->sidedist[y] = (player->map->&map[y]
			+ 1.0 - player->player[y]) * player->deltadist[y];
	}
}

static void	check_wall_hit(t_player *player)
{
	int	map[2];
	int	hit;

	hit = 0;
	map[x] = player->player[x];
	map[y] = player->player[y];
	while (hit == 0)
	{
		if (player->sidedist[x] < player->sidedist[y])
		{
			player->sidedist[x] += player->deltadist[x];
			map[x] += player->step[x];
			player->side = 0;
		}
		else
		{
			player->sidedist[y] += player->deltadist[y];
			map[y] += player->step[y];
			player->side = 1;
		}
		if (bigmap[map[x]][map[y]] > 0)
			hit = 1;
	}
	perpendicular(player);
}
