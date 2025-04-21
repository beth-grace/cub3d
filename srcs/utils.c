/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 21:06:56 by beefie            #+#    #+#             */
/*   Updated: 2025/04/21 23:16:17 by cadlard          ###   ########.fr       */
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

void vec2_normalise(double vec[2])
{
	double	mag;

	mag = sqrt(vec[X] * vec[X] + vec[Y] * vec[Y]);
	if (mag == 0.0)
		return ;
	vec[X] /= mag;
	vec[Y] /= mag;
}
