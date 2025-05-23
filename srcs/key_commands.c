/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:20:32 by beefie            #+#    #+#             */
/*   Updated: 2025/04/24 23:22:38 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cubed.h"

void	draw_square(t_cubed *game, int x, int y, int colour)
{
	int	i;
	int	j;

	i = 0;
	while (i < MAP_ZOOM && x + i < WIDTH)
	{
		j = 0;
		while (j < MAP_ZOOM && y + j < HEIGHT)
		{
			set_pix(game->mlx.img, x + i, y + j, colour);
			j++;
		}
		i++;
	}
}

static void	map_gen2(t_cubed *game, int h, int w)
{
	if (game->map[h][w] == 'S')
		draw_square(game, w * MAP_ZOOM, h * MAP_ZOOM, 0x00FF00);
	else if (game->map[h][w] == 'W')
		draw_square(game, w * MAP_ZOOM, h * MAP_ZOOM, 0x00FF00);
	else if (game->map[h][w] != ' ')
		draw_square(game, w * MAP_ZOOM, h * MAP_ZOOM, 0xFF0000);
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
		while (game->map[h][w] != '\0')
		{
			if (game->map[h][w] == '1')
				draw_square(game, w * MAP_ZOOM, h * MAP_ZOOM, 0xFFFFFF);
			else if (game->map[h][w] == '0')
				draw_square(game, w * MAP_ZOOM, h * MAP_ZOOM, 0x5F5F5F);
			else if (game->map[h][w] == 'N')
				draw_square(game, w * MAP_ZOOM, h * MAP_ZOOM, 0x00FF00);
			else if (game->map[h][w] == 'E')
				draw_square(game, w * MAP_ZOOM, h * MAP_ZOOM, 0x00FF00);
			else
				map_gen2(game, h, w);
			w++;
		}
		h++;
	}
}

void	char_error(t_cubed *game)
{
	puterr("Error\nMap has invalid Syntax.\n");
	while (game->h >= 0)
		free(game->map[game->h--]);
	free(game->map);
	exit_cleanly(game, 0);
}

bool	is_map_line(const char *line)
{
	int	i;

	if (line[0] == '\0')
		return (false);
	i = 0;
	while (line[i] != '\0')
	{
		if (ft_strchr(" NESW10", line[i]) == NULL)
			return (false);
		i++;
	}
	return (true);
}
