/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:58:16 by cadlard           #+#    #+#             */
/*   Updated: 2025/04/24 00:41:11 by beefie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_setup.h"
#include "cubed.h"

void	skip_whitespace(const char *str, int *i)
{
	while (ft_isspace(str[*i]))
		(*i)++;
}

static void	init_game(t_cubed *game)
{
	game->player.game = game;
	game->width = 0;
	game->height = 0;
	game->player_c = 0;
}

int	main(int argc, char *argv[])
{
	t_cubed	game;
	t_image	img_hack;

	if (check_cub(argc, argv) == 1)
		return (1);
	ft_memset(&game, 0, sizeof(game));
	init_game(&game);
	ft_printf("init game\n");
	mlx_setup(&game, &img_hack);
	ft_printf("mlx setup\n");
	map_size(&game, argv[1]);
	ft_printf("got map size\n");
	read_map(&game, argv[1]);
	ft_printf("read_map\n");
	map_char_check(&game);
	ft_printf("mapcheck\n");
	data_check(&game);
	ft_printf("datacheck\n");
	set_orient(&game);
	ft_printf("set orient\n");
	if (find_path(&game) == 0)
	{
		ft_printf("Error: Map is not solvable");
		exit_cleanly(&game, 2);
	}
	mlx_loop(game.mlx.data);
	ft_printf("after mlx\n");
	return (0);
}
