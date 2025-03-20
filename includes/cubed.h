/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:26:02 by beefie            #+#    #+#             */
/*   Updated: 2025/03/20 12:08:49 by beefie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
# define CUBED_H

# include "mlx.h"
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <fcntl.h>


# define ESCAPE		0xff1b
# define KEY_W		0x77
# define KEY_S		0x73
# define KEY_A		0x61
# define KEY_D		0x64

typedef struct s_cubed
{
	int			height;
	int			width;
	int			h;
	int			w;
	int			xlocation;
	int			ylocation;
	int			player_c;
	char		**map;
	void		*walls;
}	t_cubed;

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

//key_commands
int		keycheck(int key_code, t_cubed *game);

//maze_solver
char	**copy_map(t_cubed *game);
int		maze(t_cubed *game, char **new_map, int pos_y, int pos_x);
int		find_player(t_cubed *game);

//map_tingz
void	char_check(t_cubed *game, char *line);
void	map_size(t_cubed *game, char *file);
void	read_map(t_cubed *game, char *file);

#endif
