/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:13:44 by beefie            #+#    #+#             */
/*   Updated: 2025/04/23 16:33:30 by beefie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	set_floor(t_cubed *game, char *line)
{
	game->fcolour = rgb_to_hex(line);
}

void	set_ceiling(t_cubed *game, char *line)
{
	game->ccolour = rgb_to_hex(line);
}
