/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:18:50 by beefie            #+#    #+#             */
/*   Updated: 2025/04/17 15:21:33 by cadlard          ###   ########.fr       */
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
	t_player	*player;

	index = 0;
	player = &game->player;
	player->game = game;
	while (index < WIDTH)
	{
		player->camera_x = 2 * index / (double)WIDTH -1;
		player->raydir[X] = player->look_orient[X]
			+ (player->plane[X] * player->camera_x);
		player->raydir[Y] = player->look_orient[Y]
			+ (player->plane[Y] * player->camera_x);
		if (player->raydir[X] == 0)
			player->deltadist[X] = 0;
		else
			player->deltadist[X] = fabs(1.0 / player->raydir[X]);
		if (player->raydir[Y] == 0)
			player->deltadist[Y] = 0;
		else
			player->deltadist[Y] = fabs(1.0 / player->raydir[Y]);
		calc_step(player);
		check_wall_hit(player);
		if (!isnan(player->perp))
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
