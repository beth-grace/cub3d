/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:35:41 by cadlard           #+#    #+#             */
/*   Updated: 2025/04/22 17:16:19 by cadlard          ###   ########.fr       */
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

static inline void	rotate(double vec[2], double rad)
{
	double	old_x;

	old_x = vec[X];
	vec[X] = vec[X] * cos(rad) - vec[Y] * sin(rad);
	vec[Y] = old_x * sin(rad) + vec[Y] * cos(rad);
}

int	loop_hook(t_cubed *game)
{
	t_player	*player;
	double		angle;
	double		mov_dir[2];

	player = &game->player;
	angle = M_PI * 2.0 / 360.0 * player->rot_speed;
	rotate(player->look_orient, angle);
	rotate(player->plane, angle);
	mov_dir[X] = player->mov_dir[X];
	mov_dir[Y] = player->mov_dir[Y];
	vec2_normalise(mov_dir);
	player->player[X] += player->look_orient[X] * mov_dir[Y] * MOV_SPEED;
	player->player[Y] += player->look_orient[Y] * mov_dir[Y] * MOV_SPEED;
	player->player[X] += -player->look_orient[Y] * mov_dir[X] * MOV_SPEED;
	player->player[Y] += player->look_orient[X] * mov_dir[X] * MOV_SPEED;
	if (game->rerender == 1)
	{
		draw_floor(game);
		raycast(game);
		map_gen(game);
		mlx_put_image_to_window(game->mlx.data, game->mlx.win,
			game->mlx.img->data, 0, 0);
	}
	return (0);
}

int	keydown_hook(int keycode, t_cubed *game)
{
	if (keycode == ESCAPE)
		exit_cleanly(game);
	else if (keycode == KEY_LARROW)
		game->player.rot_speed -= 5.0;
	else if (keycode == KEY_RARROW)
		game->player.rot_speed += 5.0;
	else if (keycode == KEY_W)
		game->player.mov_dir[Y] += 1.0;
	else if (keycode == KEY_S)
		game->player.mov_dir[Y] -= 1.0;
	else if (keycode == KEY_A)
		game->player.mov_dir[X] -= 1.0;
	else if (keycode == KEY_D)
		game->player.mov_dir[X] += 1.0;
	return (0);
}

int	keyup_hook(int keycode, t_cubed *game)
{
	if (keycode == KEY_LARROW)
		game->player.rot_speed += 5.0;
	else if (keycode == KEY_RARROW)
		game->player.rot_speed -= 5.0;
	else if (keycode == KEY_W)
		game->player.mov_dir[Y] -= 1.0;
	else if (keycode == KEY_S)
		game->player.mov_dir[Y] += 1.0;
	else if (keycode == KEY_A)
		game->player.mov_dir[X] += 1.0;
	else if (keycode == KEY_D)
		game->player.mov_dir[X] -= 1.0;
	return (0);
}
