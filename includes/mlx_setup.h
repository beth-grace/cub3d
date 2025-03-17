/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:58:52 by cadlard           #+#    #+#             */
/*   Updated: 2025/03/17 18:56:12 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_SETUP_H
# define MLX_SETUP_H

# include <stdbool.h>
# include <mlx.h>

# define WIDTH 800
# define HEIGHT 600

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_mlx_vars
{
	void		*mlx;
	void		*win;
	t_image		*img;
}	t_mlx_vars;

typedef struct s_hook_vars
{
	t_mlx_vars	*mlx_vars;
	bool		need_rerender;
}	t_hook_vars;


void start_cub3d(void);

#endif
