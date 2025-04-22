/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <cadlard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 23:35:24 by cadlard           #+#    #+#             */
/*   Updated: 2025/04/22 15:16:04 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

t_texture	*get_texture(t_cubed *game)
{
	if (game->player.side == 1)
	{
		if (game->player.raydir[Y] < 0)
			return (&game->textures[SO]);
		else
			return (&game->textures[NO]);
	}
	else if (game->player.raydir[X] < 0)
		return (&game->textures[EA]);
	else
		return (&game->textures[WE]);
}

int	get_tex_x(t_cubed *game, t_texture *tex)
{
	t_player	*player;
	double		wall_x;
	int			tex_x;

	player = &game->player;
	if (player->side == 0)
		wall_x = player->player[Y] + player->perp * player->raydir[Y];
	else
		wall_x = player->player[X] + player->perp * player->raydir[X];
	wall_x -= floor(wall_x);
	tex = get_texture(game);
	tex_x = wall_x * tex->width;
	if (player->side == 0 && player->raydir[X] > 0)
		tex_x = tex->width - tex_x - 1;
	else if (player->side == 1 && player->raydir[Y] < 0)
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}

void	draw_texture(t_cubed *game, int index, t_draw_ctx ctx)
{
	int			tex_x;
	int			tex_y;
	double		step;
	double		tex_pos;
	t_texture	*tex;

	tex = get_texture(game);
	tex_x = get_tex_x(game, tex);
	step = (double)tex->height / ctx.height;
	tex_pos = (ctx.start - HEIGHT / 2 + ctx.height / 2) * step;
	while (ctx.start <= ctx.end && ctx.start < HEIGHT)
	{
		tex_y = (int)tex_pos & (tex->height - 1);
		tex_pos += step;
		set_pix(game->mlx.img, index, ctx.start++,
			get_pix(&tex->img, tex_x, tex_y));
	}
}
