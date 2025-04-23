/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:33:36 by cadlard           #+#    #+#             */
/*   Updated: 2025/04/23 17:14:55 by beefie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	puterr(const char *err)
{
	write(2, err, ft_strlen(err));
}

void	free_message(char *line, char *str, t_cubed *game)
{
	free(line);
	puterr(str);
	exit_cleanly(game, 2);
}
