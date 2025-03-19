/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tingz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:15:04 by beefie            #+#    #+#             */
/*   Updated: 2025/03/19 21:46:27 by beefie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	map_size(t_cubed *game, char *file)
{
	int		*line;
	int		fd;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (game->width == 0)
			game->width = ft_strlen(line) - 1;
		else if (game->width < (int)ft_strlen(line) - 1)
			game->width = ft_strlen(line) -1;
		char_check(game,line);
		game->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void char_check(t_cubed *game, char *line)
{
	int index;

	index = 0;
	while (line[index])
	{
		if (line[index] == 'P')
			game->player_c++;
		index++;
	}
}

void	map_char_check(t_cubed *game)
{
	int	i;

	if (game->player_c != 1 || map_wall_check(game))
	{
		ft_printf("Error!:\nI Don't Like It >:((\n");
		i = 0;
		while (i < game->height)
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
		exit(1);
	}
}

void	read_map(t_cubed *game, char *file)
{
	int		index;
	int		fd;

	index = 0;
	fd = open(file, O_RDONLY);
	game->map = (char **)malloc((game->height + 1) * sizeof(char *));
	while (index < game->height)
	{
		game->map[index] = get_next_line(fd);
		index++;
	}
	close(fd);
}
