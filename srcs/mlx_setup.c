/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:58:43 by cadlard           #+#    #+#             */
/*   Updated: 2025/03/24 20:42:01 by beefie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "cubed.h"
#include "mlx_setup.h"
#include "error.h"

static int	init_win(t_mlx *vars, t_image *img)
{
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		return (0);
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "cub3d");
	if (vars->win == NULL)
	{
		free(vars->mlx);
		return (0);
	}
	img->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (img->img == NULL)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->mlx);
		return (0);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	vars->img = img;
	return (1);
}

/*
	... in X11/X.h ...
	#define DestroyNotify 17
	#define StructureNotifyMask 1L << 17
*/
void	start_cub3d(t_cubed *game)
{
	t_image		img;
	t_mlx	mlx;

	game->rerender = 1;
	game->mlx = &mlx;
	if (init_win(&mlx, &img) == 0)
	{
		puterr("Failed to initialise a window\n");
		return ;
	}
	
	mlx_loop_hook(mlx.mlx, loop_hook, &game);
	mlx_key_hook(mlx.win, key_hook, &game);
	mlx_mouse_hook(mlx.win, mouse_hook, &game);
	mlx_hook(mlx.win, 17, 1L << 17, exit_cleanly, &game);
	mlx_loop(mlx.mlx);
}

