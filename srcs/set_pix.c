/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:17:56 by cadlard           #+#    #+#             */
/*   Updated: 2025/04/24 00:40:24 by beefie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>

#include "mlx_setup.h"

static inline int	byte_offset(t_image *img, int x, int y)
{
	return (y * img->line_length + x * (img->bits_per_pixel / 8));
}

int	get_pix(t_image *img, int x, int y)
{
	char	*dst;

	dst = img->addr + byte_offset(img, x, y);
	return (*(int *)dst);
}

// x * 4 == x * (image->bits_per_pixel / 8)
// y * WIDTH * 4 == y * img->line_length
void	set_pix(t_image *img, int x, int y, int colour)
{
	char	*dst;

	dst = img->addr + byte_offset(img, x, y);
	*(unsigned int *)dst = colour;
}
/*int	argb(unsigned char a,
	unsigned char r, unsigned char g, unsigned char b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}*/
