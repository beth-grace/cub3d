/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:50:05 by beefie            #+#    #+#             */
/*   Updated: 2025/04/16 14:51:24 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cubed.h"

/*static t_line	set_line(int *start, int *end)
{
	t_line	line;

	line.dx = abs(end[X] - start[X]);
	line.dy = abs(end[Y] - start[Y]);

	if (start[X] < end[X])
		line.sx = 1;
	else
		line.sx = -1;
	if (start[Y] < end[Y])
		line.sy = 1;
	else
		line.sy = -1;
	line.err = line.dx - line.dy;
	return (line);
}
//ripped someones bresenham algo implementation
//calculates best pixel to draw lines with
void	draw_line(t_image *img, int *start, int *end, int colour)
{
	t_line	line;
	int	x0;
	int	y0;
	int	e2;

	x0 = start[X];
	y0 = start[Y];
	line = set_line(start, end);
	while (x0 != end[X] || y0 != end[Y])
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
} */

static void	perp(t_player *player)
{
	if (player->side == 1)
		player->perp = player->sidedist[Y] - player->deltadist[Y];
	else
		player->perp = player->sidedist[X] - player->deltadist[X];
}

//dda algo shoutout lodev
void calc_step(t_player *player)
{
	double	diff[2];

	diff[X] = player->player[X] - (int)player->player[X];
	diff[Y] = player->player[Y] - (int)player->player[Y];
	if (player->raydir[X] < 0)
	{
		player->step[X] = -1;
		player->sidedist[X] = diff[X] * player->deltadist[X];
	}
	else
	{
		player->step[X] = 1;
		player->sidedist[X] = (1 - diff[X]) * player->deltadist[X];
	}
	if (player->raydir[Y] < 0)
	{
		player->step[Y] = -1;
		player->sidedist[Y] = diff[Y] * player->deltadist[Y];
	}
	else
	{
		player->step[Y] = 1;
		player->sidedist[Y] = (1 - diff[Y]) * player->deltadist[Y];
	}
}

void	check_wall_hit(t_player *player)
{
	int	map[2];
	int	hit;

	hit = 0;
	map[X] = player->player[X];
	map[Y] = player->player[Y];
	while (hit == 0)
	{
		if (player->sidedist[X] < player->sidedist[Y])
		{
			player->sidedist[X] += player->deltadist[X];
			map[X] += player->step[X];
			player->side = 0;
		}
		else
		{
			player->sidedist[Y] += player->deltadist[Y];
			map[Y] += player->step[Y];
			player->side = 1;
		}
		if (map[Y] < 0 || map[X] < 0 
			|| map[Y] >= player->game->height 
			|| map[X] >= (int)ft_strlen(player->game->map[map[Y]])
			|| player->game->map[map[Y]][map[X]] == 1)
			hit = 1;
	}
	perp(player);
}
