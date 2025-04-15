/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:18:50 by beefie            #+#    #+#             */
/*   Updated: 2025/04/15 20:48:53 by beefie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	raycast(t_cubed *game)
{
	int			index;
	t_player	*player;

	index = 0;
	player = &game->player;
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
	//ft_printf("in draw wall");
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
	ft_printf("%d %d\n", start, end);
	while(start <= end)
	{
		ft_printf("%d\n",game->player.side);
		if (game->player.side == 0)
		{
			set_pix(game->mlx.img,index,start++,GREEN);
			ft_printf("drawn green line");
		}
		else
			set_pix(game->mlx.img,index,start++,YELLOW);
	}
}


void	draw_floor(t_cubed *game)
{
	int x;
	int y;
	int colour;
	
	colour = RED;
	while(y <= HEIGHT)
	{
		if (y >= HEIGHT / 2)
			colour = BLUE;
		while(x <= WIDTH)
			set_pix(game->mlx.img,x++,y,colour);
		x = 0;
		y++;
	}
}
