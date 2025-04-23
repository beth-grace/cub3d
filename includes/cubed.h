/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:26:02 by beefie            #+#    #+#             */
/*   Updated: 2025/04/23 14:37:34 by cadlard          ###   ########.fr       */
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
# include <math.h>


# define MOV_SPEED	0.05
# define ESCAPE		0xff1b
# define KEY_W		0x77
# define KEY_S		0x73
# define KEY_A		0x61
# define KEY_D		0x64
# define KEY_LARROW	65361
# define KEY_RARROW	65363
# define TILE_W		64
# define TILE_H		64
# define HEIGHT		1200
# define WIDTH		1600

# define BLACK 0x00000000
# define BLUE  0x000000FF
# define GREEN 0x0000FF00
# define RED 0x00FF0000
# define YELLOW 0x00FFFF00
# define WHITE 0x00FFFFFF

# define MAP_ZOOM 8
# define X 0
# define Y 1
# define TARGET_FPS 1500
# define PRINT_FPS 1
# define MAX_RAY_CHECKS 1000
//# define DBL_MIN 2.2250738585072014e-308
//# define DBL_MAX 1.7976931348623157e+308
# define M_PI 3.14159265358979323846

typedef enum e_dir
{
	NO = 0,
	SO = 1,
	WE = 2,
	EA = 3
}	t_dir;

typedef struct s_draw_ctx
{
	int start;
	int	end;
	int	height;
}	t_draw_ctx;

typedef struct s_texture
{
	t_image	img;
	int		height;
	int		width;
	bool	valid;
}	t_texture;

typedef struct s_map
{
	int		pos_x;
	int		pos_y;
}	t_map;


struct s_cubed;
typedef struct	s_player
{
	double	player[2];
	double	plane[2];
	struct s_cubed	*game;
	double	camera_x;
	double	raydir[2];
	double	deltadist[2];
	double	sidedist[2];
	double	rotation;
	double	rot_speed;
	double	mov_dir[2];
	double	look_orient[2];
	double	perp;
	int		step[2];
	int		side;
	t_map	*map;
}	t_player;

typedef struct s_cubed
{
	int			height;
	int			width;
	int			player_c;
	int			h;
	int			w;
	int			xlocation;
	int			ylocation;
	int			orient;
	char		**map;
	void		*walls;
	t_mlx		mlx;
	bool		rerender;
	t_player	player;
	t_texture	textures[4];
	bool		duplicate_tex;
}	t_cubed;

/*typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;*/

//Brehensen's line
/*typedef struct s_line
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
}	t_line;*/


//key_commands
int		keycheck(int key_code, t_cubed *game);
void	map_gen(t_cubed *game);
void	char_error(t_cubed *game);

//maze_solver
char	**copy_map(t_cubed *game);
int		maze(t_cubed *game, char **new_map, int pos_y, int pos_x);
int		find_player(t_cubed *game);

//data_tingz
void	data_check(t_cubed *game);
bool	is_data_line(const char *line);
void	add_data(t_cubed *game, char *line);
void	strip_whitespace(char *str);

//map_tingz
void	char_check(t_cubed *game, char *line, int line_num);
void	map_char_check(t_cubed *game);
void	map_size(t_cubed *game, char *file);
void	read_map(t_cubed *game, char *file);
void	set_orient(t_cubed *game);

//map_render
void	draw_line(t_image *img, int *start, int *end, int colour);
void	calc_step(t_player *player);
void	check_wall_hit(t_player *player);

//raycast
void	raycast(t_cubed *game);
void	draw_wall(t_cubed *game,int index);
void	draw_floor(t_cubed *game);

//hooks
int	loop_hook(t_cubed *game);
int	keydown_hook(int keycode, t_cubed *game);
int	keyup_hook(int keycode, t_cubed *game);
int	mouse_hook(int mousecode, int x, int y, t_cubed *game);
int	exit_cleanly(t_cubed *game, int code);

//set_pix.c
int		get_pix(t_image *img, int x, int y);
void	set_pix(t_image *img, int x, int y, int colour);

//mlx_setup
void	mlx_setup(t_cubed *game, t_image *img);

//map_render
void	draw_line(t_image *img,int *start, int *end,int colour);
void	perpendicular(t_player *player);

//utils
int	deg_to_rad(int n);
int	rad_to_deg(int n);
int	parse_line(t_cubed *game, char *line, int *map_index);
void	vec2_normalise(double vec[2]);
void	vec2_trunc_copy(int dst[2], const double src[2]);
void	skip_whitespace(const char *str, int *i);

//texture
t_texture	*get_texture(t_cubed *game);
void	draw_texture(t_cubed *game, int index, t_draw_ctx ctx);

#endif
