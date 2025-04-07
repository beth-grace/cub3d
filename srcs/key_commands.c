/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:20:32 by beefie            #+#    #+#             */
/*   Updated: 2025/04/07 15:37:00 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cubed.h"

/*int keycheck(int key_code, t_cubed *game)
{
//	int	pot_y;
//	int pot_x;

	pot_y = 1;
	pot_x = 1;
	pot_y = game->ylocation;
	pot_x = game->xlocation;
	ft_printf("keycode: '%i'\n");
	
	if (key_code == ESCAPE) {}
	else if (key_code == KEY_W){}
	else if (key_code == KEY_A) {}
	else if (key_code == KEY_S) {}
	else if (key_code == KEY_D) {}
	else
		return(0);
	//moving(game this function will change point of view));
	return (0);
}*/

/*void	moving(t_cubed *game, int pos_y, int pox_x)
{
	if (game->map[pot_y][pot_x] == '1')
	{}
}
*/

void draw_square(t_cubed *game, int x, int y, int colour)
{
	int	i;
	int	j;

	i = 0;
	while (i < MAP_ZOOM && x + i < WIDTH)
	{
		j = 0;
		while (j < MAP_ZOOM && y + j < HEIGHT)
		{
			set_pix(game->mlx->img, x + i, y + j, colour);
			j++;
		}
		i++;
	}
}

void	map_gen(t_cubed *game)
{
	int	h;
	int	w;

	draw_square(game, 10000000, 200, 0xFFFFFF);
	h = 0;
	while (h < game->height)
	{
		w = 0;
		while (w < game->width)
		{
			if (game->map[h][w] == '1')
				draw_square(game, w * MAP_ZOOM, h * MAP_ZOOM, 0xFFFFFF);
			else if (game->map[h][w] == '0')
				draw_square(game, w * MAP_ZOOM, h * MAP_ZOOM, 0x5F5F5F);
			else if (game->map[h][w] == 'N')
				draw_square(game, w * MAP_ZOOM, h * MAP_ZOOM, 0x00FF00);
			else if (game->map[h][w] == 'E')
				draw_square(game, w * MAP_ZOOM, h * MAP_ZOOM, 0x00FF00);
			else if (game->map[h][w] == 'S')
				draw_square(game, w * MAP_ZOOM, h * MAP_ZOOM, 0x00FF00);
			else if (game->map[h][w] == 'W')
				draw_square(game, w * MAP_ZOOM, h * MAP_ZOOM, 0x00FF00);
			else if (game->map[h][w] == ' ')
				draw_square(game, w * MAP_ZOOM, h * MAP_ZOOM, 0x00FF00);
			else
				draw_square(game, w * MAP_ZOOM, h * MAP_ZOOM, 0xFF0000);
			w++;
		}
		h++;
	}
}

void	char_error(t_cubed *game)
{
	ft_printf("Error!\nMap has invalid Syntax.\n");
	while (game->h >= 0)
		free(game->map[game->h--]);
	free(game->map);
	exit(0);
}
