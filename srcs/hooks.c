/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:35:41 by cadlard           #+#    #+#             */
/*   Updated: 2025/04/16 15:50:12 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include "libft.h"
#include <math.h>

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

static inline void rotate(double vec[2], double rad)
{
	double old_x;

	old_x = vec[X];
	vec[X] = vec[X] * cos(rad) - vec[Y] * sin(rad);
	vec[Y] = old_x * sin(rad) + vec[Y] * cos(rad);
}

int	loop_hook(t_cubed *game)
{
	if (game->rerender == 1)
	{
		// !!! update image here !!!
		draw_floor(game);
		raycast(game);
	    map_gen(game);
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
	} else if (keycode == KEY_A)
	{
		double angle = -M_PI * 2.0 / 180.0;
		rotate(game->player.look_orient, angle);
		rotate(game->player.plane, angle);
	}
	else if (keycode == KEY_D)
	{
		double angle = M_PI * 2.0 / 180.0;
		rotate(game->player.look_orient, angle);
		rotate(game->player.plane, angle);
	} else if (keycode == KEY_W)
	{
		game->player.player[X] += game->player.look_orient[X] * 0.2;
		game->player.player[Y] += game->player.look_orient[Y] * 0.2;
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
