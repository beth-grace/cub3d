/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:18:50 by beefie            #+#    #+#             */
/*   Updated: 2025/04/21 23:31:57 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static t_dir get_wall_direction(t_player *player)
{
	if (player->side == 1)
	{
		if (player->raydir[Y] < 0)
			return (SO);
		else
			return (NO);
	}
	else if (player->raydir[X] < 0)
		return (EA);
	else
		return (WE);
}

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
			draw_wall(game,index);
		index++;
	}
}


void	draw_wall(t_cubed *game, int index)
{
	t_player	*player;
	double		wall_x;
	int			tex_x;
	t_dir		tex_dir;

	player = &game->player;
	tex_dir = get_wall_direction(player);
	if (player->side == 0)
		wall_x = player->player[Y] + player->perp * player->raydir[Y];
	else
		wall_x = player->player[X] + player->perp * player->raydir[X];
	wall_x -= floor(wall_x);
	tex_x = wall_x * game->textures[tex_dir].width;
	if (player->side == 0 && player->raydir[X] > 0)
		tex_x = game->textures[tex_dir].width - tex_x - 1;
	else if (player->side == 1 && player->raydir[Y] < 0)
		tex_x = game->textures[tex_dir].width - tex_x - 1;
	int	height;
	int	start;
	int	end;

	height = (int)(HEIGHT / game->player.perp);
	start = -height / 2 + HEIGHT / 2;
	if (start < 0)
		start = 0;
	end = height / 2 + HEIGHT / 2;
	if(end >= HEIGHT)
		end = HEIGHT - 1;
	else if( end < 0)
		end = -end;
	double step = (double)game->textures[tex_dir].height / height;
	double tex_pos = (start - HEIGHT / 2 + height / 2) * step;
	while (start <= end && start < HEIGHT)
	{
		int tex_y = (int)tex_pos & (game->textures[tex_dir].height - 1);
		tex_pos += step;
		int color = get_pix(&game->textures[tex_dir].img, tex_x, tex_y);
		if (player->side == 1)
			color = (color >> 1) & 8355711;
		set_pix(game->mlx.img, index, start++, color);
	}
}

void	draw_floor(t_cubed *game)
{
	int x;
	int y;
	int colour;
	
	colour = 0x848484;
	y = 0;
	while(y <= HEIGHT)
	{
		if (y >= HEIGHT / 2)
			colour = 0x424242;
		x = 0;
		while(x <= WIDTH)
			set_pix(game->mlx.img,x++,y,colour);
		y++;
	}
}
