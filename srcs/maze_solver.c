/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maze_solver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:17:26 by beefie            #+#    #+#             */
/*   Updated: 2025/04/24 23:25:08 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

char	**copy_map(t_cubed *game)
{
	char	**new_map;
	int		i;

	i = -1;
	new_map = ft_calloc(game->height, sizeof(char *));
	while (++i < game->height)
		new_map[i] = ft_strdup(game->map[i]);
	return (new_map);
}

int	find_path(t_cubed *game)
{
	char	**newmap;
	int		out;
	int		index;

	index = game->height - 1;
	newmap = copy_map(game);
	newmap[game->ylocation][game->xlocation] = '0';
	out = maze(game, newmap, game->ylocation, game->xlocation);
	while (index >= 0)
		free(newmap[index--]);
	free(newmap);
	return (out);
}

int	maze(t_cubed *game, char **new_map, int pos_y, int pos_x)
{
	if (pos_y < 0 || pos_x < 0)
		return (0);
	if (pos_y > game->height - 1
		|| pos_x > ((int)ft_strlen(new_map[pos_y]) - 1))
		return (0);
	if (new_map[pos_y][pos_x] == '1')
		return (1);
	if (new_map[pos_y][pos_x] == 'A')
		return (1);
	if (new_map[pos_y][pos_x] == ' ')
		return (0);
	new_map[pos_y][pos_x] = 'A';
	return (maze(game, new_map, pos_y + 1, pos_x)
		&& maze(game, new_map, pos_y - 1, pos_x)
		&& maze(game, new_map, pos_y, pos_x + 1)
		&& maze(game, new_map, pos_y, pos_x - 1));
}

int	check_cub(int argc, char **argv)
{
	if (argc != 2)
	{
		puterr("Error\nInvalid file type!\n");
		return (1);
	}
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 5) == 0)
		return (0);
	puterr("Error\nInvalid file type!\n");
	return (1);
}
