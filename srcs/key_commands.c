/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:20:32 by beefie            #+#    #+#             */
/*   Updated: 2025/03/20 09:54:12 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "cubed.h"

int keycheck(int key_code, t_cubed *game)
{
	int	pot_y;
	int pot_x;

	pot_y = 1;
	pot_x = 1;
	pot_y = game->ylocation;
	pot_x = game->xlocation;
	ft_printf("keycode: '%i'\n");
	if (key_code == ESCAPE) {}
	else if (key_code == KEY_W) {}
	else if (key_code == KEY_A) {}
	else if (key_code == KEY_S) {}
	else if (key_code == KEY_D) {}
	//gift
	//moving(game /*this function will change point of view)*/);
	return (0);
}
