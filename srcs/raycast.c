/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:18:50 by beefie            #+#    #+#             */
/*   Updated: 2025/04/16 17:46:33 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

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
		draw_wall(game,index);
		//ft_printf("drawn one line");
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
	if (player->side == 0)
		wall_x = player->player[Y] + player->perp * player->raydir[Y];
	else
		wall_x = player->player[X] + player->perp * player->raydir[X];
	wall_x -= floor(wall_x);
	tex_x = wall_x * game->textures[0].width;
	if (player->side == 0 && player->raydir[X] > 0)
	{
		tex_x = game->textures[0].width - tex_x - 1;
		tex_dir = 
	}
	else if (player->side == 1 && player->raydir[Y] < 0)
	{
		tex_x = game->textures[0].width - tex_x - 1;
	}
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
	double step = (double)game->textures[0].height / height;
	double tex_pos = (start - HEIGHT / 2 + height / 2) * step;
	while (start < end && start < HEIGHT)
	{
		int tex_y = (int)tex_pos & (game->textures[0].height - 1);
		tex_pos += step;
		int color = get_pix(&game->textures[0].img, tex_x, tex_y);
		if (player->side == 1)
			color = (color >> 1) & 8355711;
		set_pix(game->mlx.img, index, start++, color);
	}
}

	/*long long	height;
	long long	start;
	long long	end;

	height = (int)(HEIGHT / game->player.perp);
	start = -height / 2 + HEIGHT / 2;
	if (start < 0)
		start = 0;
	end = height / 2 + HEIGHT / 2;
	if(end >= HEIGHT)
		end = HEIGHT - 1;
	else if( end < 0)
		end = -end;
	while(start <= end && start < HEIGHT)
	{
		if (game->player.side == 0)
			set_pix(game->mlx.img,index,start++,GREEN);
		else
			set_pix(game->mlx.img,index,start++,YELLOW);
	}*/
void	draw_floor(t_cubed *game)
{
	int x;
	int y;
	int colour;
	
	colour = RED;
	y = 0;
	while(y <= HEIGHT)
	{
		if (y >= HEIGHT / 2)
			colour = BLUE;
		x = 0;
		while(x <= WIDTH)
			set_pix(game->mlx.img,x++,y,colour);
		y++;
	}
}
