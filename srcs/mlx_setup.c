/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:58:43 by cadlard           #+#    #+#             */
/*   Updated: 2025/04/16 16:35:07 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "cubed.h"
#include "mlx_setup.h"
#include "error.h"

static int	init_win(t_mlx *mlx, t_image *img)
{
	mlx->data = mlx_init();
	if (mlx->data == NULL)
		return (0);
	mlx->win = mlx_new_window(mlx->data, WIDTH, HEIGHT, "cub3d");
	if (mlx->win == NULL)
	{
		free(mlx->data);
		return (0);
	}
	img->data = mlx_new_image(mlx->data, WIDTH, HEIGHT);
	if (img->data == NULL)
	{
		mlx_destroy_window(mlx->data, mlx->win);
		free(mlx->data);
		return (0);
	}
	img->addr = mlx_get_data_addr(img->data, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	mlx->img = img;
	return (1);
}

/*
	... in X11/X.h ...
	#define DestroyNotify 17
	#define StructureNotifyMask 1L << 17
*/
void	mlx_setup(t_cubed *game, t_image *img_hack)
{
	game->rerender = 1;
	if (init_win(&game->mlx, img_hack) == 0)
	{
		puterr("Failed to initialise a window\n");
		return ;
	}
	mlx_loop_hook(game->mlx.data, loop_hook, game);
	mlx_mouse_hook(game->mlx.win, mouse_hook, game);
	mlx_hook(game->mlx.win, 17, 1L << 17, exit_cleanly, game);
	mlx_hook(game->mlx.win, 2, 1L << 0, key_hook, game);
}

