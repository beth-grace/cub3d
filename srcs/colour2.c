/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:13:44 by beefie            #+#    #+#             */
/*   Updated: 2025/04/24 00:40:03 by beefie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	set_floor(t_cubed *game, char *line)
{
	if (!game->f_isset)
	{
		game->fcolour = rgb_to_hex(line, game);
		game->f_isset = 1;
	}
	else
		free_message(line, "Too many Chars!!\n", game);
}

void	set_ceiling(t_cubed *game, char *line)
{
	if (!game->c_isset)
	{
		game->ccolour = rgb_to_hex(line, game);
		game->c_isset = 1;
	}
	else
		free_message(line, "Too many Chars!!\n", game);
}
