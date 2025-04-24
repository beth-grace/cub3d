/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_tingz.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:41:44 by cadlard           #+#    #+#             */
/*   Updated: 2025/04/24 22:26:15 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <mlx.h>
#include "cubed.h"

void	data_check(t_cubed *game)
{
	int	i;

	if (game->duplicate_tex)
	{
		ft_printf("Error\nDuplicate texture\n");
		exit_cleanly(game, 2);
	}
	i = 0;
	while (i < 4)
	{
		if (game->textures[i].valid == false)
		{
			ft_printf("Error\nUnspecified/Invalid texture\n");
			exit_cleanly(game, 2);
		}
		i++;
	}
}

bool	is_data_line(const char *line)
{
	int	i;

	if (line == NULL)
		return (false);
	i = 0;
	skip_whitespace(line, &i);
	return (
		ft_strncmp(line + i, "NO", 2) == 0
		|| ft_strncmp(line + i, "SO", 2) == 0
		|| ft_strncmp(line + i, "EA", 2) == 0
		|| ft_strncmp(line + i, "WE", 2) == 0
		|| ft_strncmp(line + i, "F", 1) == 0
		|| ft_strncmp(line + i, "C", 1) == 0
	);
}

void	strip_whitespace(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i >= 0 && ft_isspace(str[i]))
	{
		str[i] = '\0';
		i--;
	}
}

static void	add_texture(t_cubed *game, char *line, t_dir dir)
{
	int			i;
	char		*path_ptr;
	t_rex		*tex;

	tex = &(game->textures[dir]);
	if (tex->valid)
	{
		game->duplicate_tex = true;
		return ;
	}
	i = 2;
	skip_whitespace(line, &i);
	path_ptr = line + i;
	tex->img.data = mlx_xpm_file_to_image(game->mlx.data, path_ptr,
			&tex->width, &tex->height);
	if (tex->img.data == NULL)
	{
		ft_printf("Bad texture: '%s'\n", path_ptr);
		return ;
	}
	tex->img.addr = mlx_get_data_addr(tex->img.data, &tex->img.bits_per_pixel,
			&tex->img.line_length, &tex->img.endian);
	tex->valid = true;
}

void	add_data(t_cubed *game, char *line)
{
	int	i;

	i = 0;
	skip_whitespace(line, &i);
	line += i;
	if (ft_strncmp(line, "NO", 2) == 0)
		add_texture(game, line, NO);
	else if (ft_strncmp(line, "SO", 2) == 0)
		add_texture(game, line, SO);
	else if (ft_strncmp(line, "EA", 2) == 0)
		add_texture(game, line, EA);
	else if (ft_strncmp(line, "WE", 2) == 0)
		add_texture(game, line, WE);
	else if (ft_strncmp(line, "F ", 2) == 0)
		set_floor(game, line);
	else if (ft_strncmp(line, "C ", 2) == 0)
		set_ceiling(game, line);
}
