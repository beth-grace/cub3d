/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:20:32 by beefie            #+#    #+#             */
/*   Updated: 2025/03/19 19:08:18 by beefie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int keycheck(int key_code, t_cubed *game)
{
	int	pot_y;
	int pot_x;

	pot_y = 1;
	pot_x = 1;
	pot_y = game->ylocation;
	pot_x = game->xlocation;
	if (key_code == ESCAPE)
		//game_closed(game);
	else if (key_code == KEY_W)
	//dis you coby;
	else if (key_code == KEY_A)
	//still you;
	else if (key_code == KEY_S)
	//youuuu
	else if (key_code == KEY_D)
	//gift
	moving(game /*this function will change point of view)*/);
	return (0);
}
