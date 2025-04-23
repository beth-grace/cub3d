/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maze_solver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:17:26 by beefie            #+#    #+#             */
/*   Updated: 2025/04/24 00:37:46 by beefie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

char	**copy_map(t_cubed *game)
{
	char	**new_map;
	int		i;

	i = -1;
	new_map = malloc(sizeof(char *) * game->height);
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
	if (pos_y > game->height -1 || pos_x > game->width -1)
		return (0);
	if (new_map[pos_y][pos_x] == '1')
		return (1);
	if (new_map[pos_y][pos_x] == 'A')
		return (1);
	if (new_map[pos_y][pos_x] == ' ')
		return (0);
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
	while (pos_y <= game->height)
	{
		pos_x = -1;
		while (++pos_x <= game->width)
			if (game->map[pos_y][pos_x] == 'N'
				|| game->map[pos_y][pos_x] == 'E'
				|| game->map[pos_y][pos_x] == 'S'
				|| game->map[pos_y][pos_x] == 'W')
				break ;
		pos_y++;
	}
	out = maze(game, new_map, pos_y, pos_x);
	pos_y = game->height - 1;
	while (pos_y >= 0)
		free(new_map[pos_y - 1]);
	free(new_map);
	return (out);
}

int	check_cub(int argc, char **argv)
{
	int	index;

	index = 0;
	if (argc != 2)
	{
		ft_printf("Invalid file type!\n");
		return (1);
	}
	while (argv[1][index] != '.' && argv[1][index] != '\0')
		index++;
	ft_printf("from dot: %s\n", argv[1] + index);
	if ((argv[1][index + 1] == 'c') && (argv[1][index + 2] == 'u')
		&& (argv[1][index + 3] == 'b') && (argv[1][index + 4] == '\0'))
		return (0);
	else
		ft_printf("Invalid file type!\n");
	return (0);
}
