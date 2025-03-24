/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:26:02 by beefie            #+#    #+#             */
/*   Updated: 2025/03/24 20:40:39 by beefie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
# define CUBED_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <fcntl.h>
# include "mlx_setup.h"
# include <mlx.h>
# include <stdbool.h>


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
	t_mlx		*mlx;
	bool		rerender;
}	t_cubed;

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

//key_commands
int		keycheck(int key_code, t_cubed *game);
void	map_gen(t_cubed *game);
void	char_error(t_cubed *game);

//maze_solver
char	**copy_map(t_cubed *game);
int		maze(t_cubed *game, char **new_map, int pos_y, int pos_x);
int		find_player(t_cubed *game);

//map_tingz
void	char_check(t_cubed *game, char *line);
void	map_char_check(t_cubed *game);
void	map_size(t_cubed *game, char *file);
void	read_map(t_cubed *game, char *file);

//hooks
int	loop_hook(t_cubed *game);
int	key_hook(int keycode, t_cubed *game);
int	mouse_hook(int mousecode, int x, int y, t_cubed *game);
int	exit_cleanly(t_cubed *game);

//set_pix.c
void	set_pix(t_image *img, int x, int y, int colour);

//mlx_setup
void	start_cub3d(t_cubed *game);
#endif
