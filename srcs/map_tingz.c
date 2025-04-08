/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tingz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:15:04 by beefie            #+#    #+#             */
/*   Updated: 2025/04/08 11:25:43 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void char_check(t_cubed *game, char *line)
{
	int index;
//checks for player orientation and valid chars
	index = 0;
	while (line[index])
	{
		if (line[index] == 'N' )
		{
			game->orient = 1;
			game->player_c++;
		}
		else if (line[index] == 'E')
		{
			game->orient = 2;
			game->player_c++;
		}
		else if (line[index] == 'S')
		{
			game->orient = 3;
			game->player_c++;
		}
		else if (line[index] == 'W')
		{
			game->orient = 4;
			game->player_c++;
		}
		index++;
	}
}
void	map_char_check(t_cubed *game)
{
	int index;
//will pick up invalid chars or too many players
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

bool is_data_line(const char *line)
{
	if (line == NULL)
		return (false);
	return (
		ft_strncmp(line, "NO", 2) == 0
		|| ft_strncmp(line, "SO", 2) == 0
		|| ft_strncmp(line, "EA", 2) == 0
		|| ft_strncmp(line, "WE", 2) == 0
		|| ft_strncmp(line, "F", 1) == 0
		|| ft_strncmp(line, "C", 1) == 0
	);
}

void	map_size(t_cubed *game, char *file)
{
	char	*line;
	int		fd;
// checks and store map height and width
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
			game->width = ft_strlen(line) -1;
		char_check(game,line);
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
//reads map/file parseing
	index = 0;
	fd = open(file, O_RDONLY);
	game->map = (char **)malloc((game->height + 1) * sizeof(char *));
	if (game->map == NULL)
		return; // TODO: L
	while (index < game->height)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line[0] == '\0' || line[0] == '\n')
		{
			free(line);
			continue ;
		}
		if (is_data_line(line))
		{
			// TODO: do stuff with data
			free(line);
			continue ;
		}
		else 
			game->map[index] = line;
		index++;
	}
	close(fd);
}

