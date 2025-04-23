/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:13:44 by beefie            #+#    #+#             */
/*   Updated: 2025/04/23 17:32:18 by beefie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	set_floor(t_cubed *game, char *line)
{
	if (!game->fcolour)
		game->fcolour = rgb_to_hex(line, game);
	else
		free_message(line,"Too many Chars!!", game);
}

void	set_ceiling(t_cubed *game, char *line)
{
	if (!game->ccolour)
		game->ccolour = rgb_to_hex(line, game);
	else
		free_message(line, "Too many Chars!!", game);
}
