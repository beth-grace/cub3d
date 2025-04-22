/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tingz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:15:04 by beefie            #+#    #+#             */
/*   Updated: 2025/04/22 15:54:12 by beefie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	char_check(t_cubed *game, char *line, int line_num)
{
	int	index;

	index = 0;
	while (line[index])
	{
		if (line[index] == 'N' )
		{
			game->orient = 1;
			game->player_c++;
			game->player.player[X] = index + 0.5;
			game->player.player[Y] = line_num + 0.5;
		}
		else if (line[index] == 'E')
		{
			game->orient = 2;
			game->player_c++;
			game->player.player[X] = index + 0.5;
			game->player.player[Y] = line_num + 0.5;
		}
		else if (line[index] == 'S' || line[index] == 'W')
			char_check2(game, line, line_num, index);
		index++;
	}
}

static void	char_check2(t_cubed *game, char *line, int line_num, int index)
{
	if (line[index] == 'S')
	{
		game->orient = 3;
		game->player_c++;
		game->player.player[X] = index + 0.5;
		game->player.player[Y] = line_num + 0.5;
	}
	else if (line[index] == 'W')
	{
		game->orient = 4;
		game->player_c++;
		game->player.player[X] = index + 0.5;
		game->player.player[Y] = line_num + 0.5;
	}
}

void	map_char_check(t_cubed *game)
{
	int	index;

	if (game->player_c != 1)
	{
		ft_printf("Error!:\nI Don't Like It >:((\n");
		ft_printf("Bad amount of players!: %i\n", game->player_c);
		index = 0;
		while (index < game->height)
		{
			free(game->map[index]);
			index++;
		}
		free(game->map);
		exit(1);
	}
}

void	map_size(t_cubed *game, char *file)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (is_data_line(line) || line[0] == '\0' || line[0] == '\n')
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		if (game->width == 0)
			game->width = ft_strlen(line) - 1;
		else if (game->width < (int)ft_strlen(line) - 1)
			game->width = ft_strlen(line) - 1;
		char_check(game, line, game->height);
		game->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	read_map(t_cubed *game, char *file)
{
	int		index;
	int		fd;
	char	*line;

	index = 0;
	fd = open(file, O_RDONLY);
	game->map = (char **)malloc((game->height + 1) * sizeof(char *));
	if (game->map == NULL)
		return ;
	while (index < game->height)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		else if (line[0] == '\0' || line[0] == '\n')
		{
			free(line);
			continue ;
		}
		strip_newline(line);
		if (is_data_line(line))
		{
			add_data(game, line);
			free(line);
			continue ;
		}
		else
			game->map[index] = line;
		index++;
	}
	close(fd);
}
