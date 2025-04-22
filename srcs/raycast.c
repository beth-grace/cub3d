/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:18:50 by beefie            #+#    #+#             */
/*   Updated: 2025/04/22 15:17:15 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	raycast(t_cubed *game)
{
	int			index;

	index = 0;
	while (index < WIDTH)
	{
		game->player.camera_x = 2 * index / (double)WIDTH -1;
		game->player.raydir[X] = game->player.look_orient[X]
			+ (game->player.plane[X] * game->player.camera_x);
		game->player.raydir[Y] = game->player.look_orient[Y]
			+ (game->player.plane[Y] * game->player.camera_x);
		if (game->player.raydir[X] == 0)
			game->player.deltadist[X] = 0;
		else
			game->player.deltadist[X] = fabs(1.0 / game->player.raydir[X]);
		if (game->player.raydir[Y] == 0)
			game->player.deltadist[Y] = 0;
		else
			game->player.deltadist[Y] = fabs(1.0 / game->player.raydir[Y]);
		calc_step(&game->player);
		check_wall_hit(&game->player);
		if (!isnan(game->player.perp))
			draw_wall(game, index);
		index++;
	}
}

void	draw_wall(t_cubed *game, int index)
{
	t_draw_ctx	ctx;

	ctx.height = (int)(HEIGHT / game->player.perp);
	ctx.start = -ctx.height / 2 + HEIGHT / 2;
	if (ctx.start < 0)
		ctx.start = 0;
	ctx.end = ctx.height / 2 + HEIGHT / 2;
	if (ctx.end >= HEIGHT)
		ctx.end = HEIGHT - 1;
	else if (ctx.end < 0)
		ctx.end = -ctx.end;
	draw_texture(game, index, ctx);
}

void	draw_floor(t_cubed *game)
{
	int	x;
	int	y;
	int	colour;

	colour = 0x848484;
	y = 0;
	while (y <= HEIGHT)
	{
		if (y >= HEIGHT / 2)
			colour = 0x424242;
		x = 0;
		while (x <= WIDTH)
			set_pix(game->mlx.img, x++, y, colour);
		y++;
	}
}
