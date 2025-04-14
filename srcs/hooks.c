/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:35:41 by cadlard           #+#    #+#             */
/*   Updated: 2025/04/14 13:09:46 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "libft.h"

#include "mlx_setup.h"
#include "cubed.h"

/*
these are only available on minilibx_linux for some reason?
	mlx_loop_end(vars->mlx);
	mlx_destroy_display(vars->mlx);
*/
int	exit_cleanly(t_cubed *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(game->mlx.data, game->textures[i].img.data);
		i++;
	}
	i = 0;
	while (i < game->height)
	{
		if (game->map[i] != NULL)
			free(game->map[i]);
		i++;
	}
	free(game->map);
	mlx_destroy_image(game->mlx.data, game->mlx.img->data);
	mlx_destroy_window(game->mlx.data, game->mlx.win);
	mlx_destroy_display(game->mlx.data);
	free(game->mlx.data);
	exit(0);
	return (0);
}

int	loop_hook(t_cubed *game)
{
	if (game->rerender == 1)
	{
		// !!! update image here !!!
		map_gen(game);
		for (int y = 0; y < game->textures[0].height; y++) {
			for (int x = 0; x < game->textures[0].width; x++) {
				set_pix(game->mlx.img, x + 150, y + 150, get_pix(&game->textures[0].img, x, y));
			}
		}
		mlx_put_image_to_window(game->mlx.data, game->mlx.win,
			game->mlx.img->data, 0, 0);
	}
	return (0);
}

int	key_hook(int keycode, t_cubed *game)
{
	if (keycode == ESCAPE)
	{
		exit_cleanly(game);
	}
	return (0);
}

int	mouse_hook(int mousecode, int x, int y, t_cubed *game)
{
	(void)x;
	(void)y;
	(void)game;
	(void)mousecode;
	return (0);
}
