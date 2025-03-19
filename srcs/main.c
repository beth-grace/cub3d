/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:58:16 by cadlard           #+#    #+#             */
/*   Updated: 2025/03/19 18:03:52 by beefie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "error.h"
#include "mlx_setup.h"

int main(int argc, char *argv[])
{
	(void)argv;
	if (argc != 2)
	{
		puterr("Usage: ./cub3d <.cub file>\n");
		return (1);
	}
	start_cub3d();
	return (0);
}
