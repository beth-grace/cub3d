/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tingz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:15:04 by beefie            #+#    #+#             */
/*   Updated: 2025/04/16 14:28:26 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void char_check(t_cubed *game, char *line, int line_num)
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
			game->player.player[X] = index;
			game->player.player[Y] = line_num;
		}
		else if (line[index] == 'E')
		{
			game->orient = 2;
			game->player_c++;
			game->player.player[X] = index;
			game->player.player[Y] = line_num;
		}
		else if (line[index] == 'S')
		{
			game->orient = 3;
			game->player_c++;
			game->player.player[X] = index;
			game->player.player[Y] = line_num;
		}
		else if (line[index] == 'W')
		{
			game->orient = 4;
			game->player_c++;
			game->player.player[X] = index;
			game->player.player[Y] = line_num;
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
		char_check(game,line, game->height);
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

//for North only atm
void	set_orient(t_cubed *game)
{
	if(game->orient == 1 || game->orient == 3)
	{
		game->player.plane[Y] = 0.0;
		game->player.look_orient[X] = 0.0;
		if (game->orient == 1)
		{
			game->player.plane[X] = 0.66;
			game->player.look_orient[Y] = -1.0;
		}
		else if (game->orient == 3)
		{
			game->player.plane[X] = -0.66;
			game->player.look_orient[Y] = 1.0;
		}
	}
	else
	{
		game->player.plane[X] = 0.0;
		game->player.look_orient[Y] = 0.0;
		if (game->orient == 2)
		{
			game->player.plane[Y] = 0.66;
			game->player.look_orient[X] = 1.0;
		}
		else if (game->orient == 4)
		{
			game->player.plane[Y] = -0.66;
			game->player.look_orient[X] = -1.0;
		}
	}
}
