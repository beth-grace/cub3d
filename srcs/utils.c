/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 21:06:56 by beefie            #+#    #+#             */
/*   Updated: 2025/04/24 23:17:51 by cadlard          ###   ########.fr       */
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

void	parse_line(t_cubed *game, char *line, int *map_index)
{
	strip_whitespace(line);
	if (is_data_line(line))
	{
		add_data(game, line);
		free(line);
	}
	else if (is_map_line(line))
	{
		game->map[*map_index] = line;
		(*map_index)++;
	}
	else if (*map_index > 0)
	{
		free(line);
		game->done_reading_map = true;
	}
	else
		free(line);
}
