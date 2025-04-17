/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:58:16 by cadlard           #+#    #+#             */
/*   Updated: 2025/04/17 15:27:47 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "error.h"
#include "mlx_setup.h"
#include "cubed.h"

static void init_game(t_cubed *game)
{
//	game->mlx = mlx_init();
	game->width = 0;
	game->height = 0;
	game->player_c = 0;
}

int main(int argc, char *argv[])
{
	t_cubed	game;
	t_image	img_hack;
	
	ft_memset(&game, 0, sizeof(game));
	if (argc != 2)
	{
		puterr("Usage: ./cub3d <.cub file>\n");
		return (1);
	}
	init_game(&game);
	ft_printf("init game\n");
	mlx_setup(&game, &img_hack);
	ft_printf("mlx setup\n");
	map_size(&game,argv[1]);
	ft_printf("got map size\n");
	read_map(&game,argv[1]);
	ft_printf("read_map\n");
	map_char_check(&game);
	ft_printf("mapcheck\n");
	data_check(&game);
	ft_printf("datacheck\n");
	set_orient(&game);
	ft_printf("set orient\n");
	mlx_loop(game.mlx.data);
	ft_printf("after mlx\n");
	return (0);
}
