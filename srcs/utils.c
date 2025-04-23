/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 21:06:56 by beefie            #+#    #+#             */
/*   Updated: 2025/04/23 16:25:32 by beefie           ###   ########.fr       */
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

void	free_message(char *line, char *str)
{
	free(line);
	ft_printf("%s\n",str);
	exit(2);
}
