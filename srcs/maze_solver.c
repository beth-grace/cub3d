/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maze_solver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:17:26 by beefie            #+#    #+#             */
/*   Updated: 2025/03/20 12:08:36 by beefie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

char	**copy_map(t_cubed *game)
{
//might be useless, can delete.
	char **new_map;
	int		i;

	i = -1;
	new_map = malloc(sizeof(char *) * game->height);
	while (++i < game->height)
		new_map[i] = ft_strdup(game->map[i]);
	return (new_map);
}

int maze(t_cubed *game, char **new_map, int pos_y, int pos_x)
{
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

	pos_y = 0;
	new_map = copy_map(game);
	while ( pos_y <= game->height)
	{
		pos_x = -1;
		while (++pos_x <= game->width)
			if (game->map[pos_y][pos_x] == 'P')
				break;
		if (game->map[pos_y][pos_x] == 'P')
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
