/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 21:06:56 by beefie            #+#    #+#             */
/*   Updated: 2025/04/24 22:54:42 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	deg_to_rad(int n)
{
	return ((n * M_PI) / 180);
}

int	rad_to_deg(int n)
{
	return ((n * 180) / M_PI);
}

void	vec2_normalise(double vec[2])
{
	double	mag;

	mag = sqrt(vec[X] * vec[X] + vec[Y] * vec[Y]);
	if (mag == 0.0)
		return ;
	vec[X] /= mag;
	vec[Y] /= mag;
}

void	vec2_trunc_copy(int dst[2], const double src[2])
{
	dst[X] = (int)src[X];
	dst[Y] = (int)src[Y];
}

#include <stdio.h>
// TODO: add check before adding line to map to make sure it is valid
void	parse_line(t_cubed *game, char *line, int *map_index)
{
	strip_whitespace(line);
	ft_printf("index: %i; ", *map_index);
	ft_printf("line: '%s'", line);
	if (is_data_line(line))
	{
		printf(" : is data\n");
		add_data(game, line);
		free(line);
	}
	else if (is_map_line(line))
	{
		printf(" : is map\n");
		game->map[*map_index] = line;
		(*map_index)++;
	}
	else if (*map_index > 0)
	{
		printf("is not map in between map\n");
		puterr("BADBADBADBADBADBADBAD");
		free(line);
		exit_cleanly(game, 2);
	}
	else
	{
		free(line);
		ft_printf("\n");
	}
}
