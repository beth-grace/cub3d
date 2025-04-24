/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:58:16 by cadlard           #+#    #+#             */
/*   Updated: 2025/04/24 23:22:25 by cadlard          ###   ########.fr       */
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
	ft_memset(game, 0, sizeof(*game));
	game->player.game = game;
	game->height = 0;
	game->player_c = 0;
}

int	main(int argc, char *argv[])
{
	t_cubed	game;
	t_image	img_hack;

	if (check_cub(argc, argv) == 1)
		return (1);
	init_game(&game);
	mlx_setup(&game, &img_hack);
	map_size(&game, argv[1]);
	read_map(&game, argv[1]);
	map_char_check(&game);
	data_check(&game);
	set_orient(&game);
	if (find_path(&game) == 0)
	{
		puterr("Error\nMap is not solvable\n");
		exit_cleanly(&game, 2);
	}
	mlx_loop(game.mlx.data);
	return (0);
}
