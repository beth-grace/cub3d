/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:50:05 by beefie            #+#    #+#             */
/*   Updated: 2025/04/18 21:02:33 by beefie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cubed.h"

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
	int	i;

	map[X] = player->player[X];
	map[Y] = player->player[Y];
	i = 0;
	while (1)
	{
		i++;
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
		if ((map[Y] < 0 || map[X] < 0 
			|| map[Y] >= player->game->height 
			|| map[X] >= (int)ft_strlen(player->game->map[map[Y]])))
		{
			if (i <= MAX_RAY_CHECKS)
				continue ;
			else
			{
				player->perp = NAN;
				return ;
			}
		}
		if (player->game->map[map[Y]][map[X]] == '1')
			break ;
	}
	perp(player);
}
