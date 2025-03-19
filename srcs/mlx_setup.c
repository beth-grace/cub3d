/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:58:43 by cadlard           #+#    #+#             */
/*   Updated: 2025/03/20 09:50:45 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>

#include "mlx_setup.h"
#include "hooks.h"
#include "error.h"

static int	init_win(t_mlx_vars *vars, t_image *img)
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
void	start_cub3d(void)
{
	t_image		img;
	t_mlx_vars	mlx_vars;
	t_hook_vars	hook_vars;

	hook_vars.mlx_vars = &mlx_vars;
	if (init_win(&mlx_vars, &img) == 0)
	{
		puterr("Failed to initialise a window\n");
		return ;
	}
	mlx_loop_hook(mlx_vars.mlx, loop_hook, &hook_vars);
	mlx_key_hook(mlx_vars.win, key_hook, &hook_vars);
	mlx_mouse_hook(mlx_vars.win, mouse_hook, &hook_vars);
	mlx_hook(mlx_vars.win, 17, 1L << 17, exit_cleanly, &hook_vars);
	mlx_loop(mlx_vars.mlx);
}
