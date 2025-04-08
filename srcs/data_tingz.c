/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_tingz.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:41:44 by cadlard           #+#    #+#             */
/*   Updated: 2025/04/08 13:21:18 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <mlx.h>
#include "cubed.h"

bool is_data_line(const char *line)
{
	if (line == NULL)
		return (false);
	return (
		ft_strncmp(line, "NO ", 3) == 0
		|| ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "EA ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0
		|| ft_strncmp(line, "F ", 2) == 0
		|| ft_strncmp(line, "C ", 2) == 0
	);
}

void	strip_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\0')
			str[i] = '\0';
		i++;
	}
}

void	add_texture(t_cubed *game, char *line, t_dir dir)
{
	int			i;
	char		*path_ptr;
	t_texture	*tex;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	path_ptr = line + i;
	tex = &game->textures[dir];
	tex->img.data = mlx_xpm_file_to_image(
		game->mlx,
		path_ptr,
		&tex->width,
		&tex->height
	);
	/*if (game->textures[dir] == NULL)
		game->textures[dir].img.data = mlx_png_file_to_image(
			game->mlx,
			path_ptr,
			&game->textures[ident].width,
			&game->textures[ident].height
		);*/
	if (tex->img.data == NULL)
	{
		ft_printf("Bad texture: '%s'\n", path_ptr);
		return;
	}
	tex->img.addr = mlx_get_data_addr(tex->img.data, &tex->img.bits_per_pixel,
		&tex->img.line_length, &tex->img.endian);
}

void	add_data(t_cubed *game, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		add_texture(game, line, NO);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		add_texture(game, line, SO);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		add_texture(game, line, EA);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		add_texture(game, line, WE);
}
