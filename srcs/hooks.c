/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:35:41 by cadlard           #+#    #+#             */
/*   Updated: 2025/04/08 12:59:56 by cadlard          ###   ########.fr       */
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
	mlx_destroy_image(game->mlx->mlx, game->mlx->img->data);
	mlx_destroy_window(game->mlx->mlx, game->mlx->win);
	mlx_destroy_display(game->mlx->mlx);
	exit(0);
	return (0);
}

int	loop_hook(t_cubed *game)
{
	game->rerender = 1;
	if (game->rerender == 1)
	{
		// !!! update image here !!!
		map_gen(game);
		mlx_put_image_to_window(game->mlx->mlx, game->mlx->win,
			game->mlx->img->data, 0, 0);
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
