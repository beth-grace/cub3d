/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:35:41 by cadlard           #+#    #+#             */
/*   Updated: 2025/03/17 19:23:05 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>

#include "mlx_setup.h"
#include "hooks.h"
#include "set_pix.h"

/*
these are only available on minilibx_linux for some reason?
	mlx_loop_end(vars->mlx_vars);
	mlx_destroy_display(vars->mlx_vars);
*/
int	exit_cleanly(t_hook_vars *hook_vars)
{
	mlx_destroy_image(hook_vars->mlx_vars->mlx, hook_vars->mlx_vars->img->img);
	mlx_destroy_window(hook_vars->mlx_vars->mlx, hook_vars->mlx_vars->win);
	mlx_destroy_display(hook_vars->mlx_vars->mlx);
	exit(0);
	return (0);
}

int	loop_hook(t_hook_vars *hook_vars)
{
	if (hook_vars->need_rerender)
	{
		// !!! update image here !!!
		set_pix(hook_vars->mlx_vars->img, 100, 100, 255);
		mlx_put_image_to_window(hook_vars->mlx_vars->mlx, hook_vars->mlx_vars->win, hook_vars->mlx_vars->img->img, 0, 0);
	}
	return (0);
}

int	key_hook(int keycode, t_hook_vars *hook_vars)
{
	if (keycode == ESCAPE_KEYCODE)
	{
		exit_cleanly(hook_vars);
	}
	return (0);
}

int	mouse_hook(int mousecode, int x, int y, t_hook_vars *hook_vars)
{
	(void)x;
	(void)y;
	(void)hook_vars;
	(void)mousecode;
	return (0);
}
