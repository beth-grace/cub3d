/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:26:02 by beefie            #+#    #+#             */
/*   Updated: 2025/03/20 09:57:00 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
# define CUBED_H

# include "mlx.h"
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <fcntl.h>


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
	void		*mlx;
	void		*walls;
	void		*player;
}	t_cubed;

int		keycheck(int key_code, t_cubed *game);
void	map_char_check(t_cubed *game);

#endif
