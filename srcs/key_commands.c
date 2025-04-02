/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:20:32 by beefie            #+#    #+#             */
/*   Updated: 2025/03/31 17:03:38 by beefie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cubed.h"

/*int keycheck(int key_code, t_cubed *game)
{
//	int	pot_y;
//	int pot_x;

	pot_y = 1;
	pot_x = 1;
	pot_y = game->ylocation;
	pot_x = game->xlocation;
	ft_printf("keycode: '%i'\n");
	
	if (key_code == ESCAPE) {}
	else if (key_code == KEY_W){}
	else if (key_code == KEY_A) {}
	else if (key_code == KEY_S) {}
	else if (key_code == KEY_D) {}
	else
		return(0);
	//moving(game this function will change point of view));
	return (0);
}*/

/*void	moving(t_cubed *game, int pos_y, int pox_x)
{
	if (game->map[pot_y][pot_x] == '1')
	{}
}
*/
void	map_gen(t_cubed *game)
{
	int	h;
	int	w;

	h = 0;
	while (h < game->height)
	{
		w = 0;
		while (w < game->width)
		{
			if (game->map[h][w] == '1')
			{
				set_pix(game->mlx->img, h, w, 0xFFFFFF);
			}
			else if (game->map[h][w] != '0' && (game->map[h][w] != 'N'
				|| game->map[h][w] != 'E' || game->map[h][w] != 'S'
					|| game->map[h][w] == 'W'))
				char_error(game);
			w++;
		}
		h++;
	}
}

void	char_error(t_cubed *game)
{
	ft_printf("Error!\nMap has invalid Syntax.\n");
	while (game->h >= 0)
		free(game->map[game->h--]);
	free(game->map);
	exit(0);
}
