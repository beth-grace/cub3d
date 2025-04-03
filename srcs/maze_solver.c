/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maze_solver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:17:26 by beefie            #+#    #+#             */
/*   Updated: 2025/04/03 21:02:30 by beefie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

char	**copy_map(t_cubed *game)
{
//might be useless, can delete.
	char **new_map;
	int		i;
//create a copy, so we arent changing the real map
	i = -1;
	new_map = malloc(sizeof(char *) * game->height);
	while (++i < game->height)
		new_map[i] = ft_strdup(game->map[i]);
	return (new_map);
}

int maze(t_cubed *game, char **new_map, int pos_y, int pos_x)
{// check if its a valid map
	if (pos_y < 0 || pos_x < 0)
		return (1);
	if (pos_y > game->height -1 || pos_x > game->width -1)
		return (1);
	if (new_map[pos_y][pos_x] == '1')
		return (0);
	if (new_map[pos_y][pos_x] == 'A')
		return (0);
	if (new_map[pos_y][pos_x] == ' ')
		return (1);
	new_map[pos_y][pos_x] = 'A';
	return (maze(game, new_map, pos_y + 1, pos_x)
		|| maze(game, new_map, pos_y - 1, pos_x)
		|| maze(game, new_map, pos_y, pos_x + 1)
		|| maze(game, new_map, pos_y, pos_x - 1));
}

int	find_player(t_cubed *game)
{
	char	**new_map;
	int		out;
	int		pos_y;
	int		pos_x;
//finds player position
	pos_y = 0;
	new_map = copy_map(game);
	while ( pos_y <= game->height)
	{
		pos_x = -1;
		while (++pos_x <= game->width)
			if (game->map[pos_y][pos_x] == 'N'
				|| game->map[pos_y][pos_x] == 'E'
				|| game->map[pos_y][pos_x] == 'S'
				|| game->map[pos_y][pos_x] == 'W')
				break;
		pos_y++;
	}
	out = maze(game, new_map, pos_y, pos_x);
	pos_y = game->height - 1;
	while (pos_y >= 0)
		free(new_map[pos_y - 1]);
	free(new_map);
	return (out);
}

void	check_cub(int argc, char **argv)
{
	int	index;
//checks if its a .cub file
	index = 0;
	while (argv[1][index] != '.')
		index++;
	if ((argv[2][index + 1] == 'c') && (argv[2][index + 2] == 'u')
		&& (argv[2][index + 3] == 'b') && (argv[2][index + 4] == ' '))
		return (0);
	return (1);
}
