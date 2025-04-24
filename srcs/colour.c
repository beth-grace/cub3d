/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 01:49:15 by beefie            #+#    #+#             */
/*   Updated: 2025/04/24 23:26:04 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static int	check_colour_codes(char *s)
{
	int	index;
	int	len;

	index = 1;
	len = ft_strlen(s);
	if (!len)
		return (0);
	while (s[++index])
	{
		while (s[index] && (ft_isspace(s[index]) || ft_isdigit(s[index])))
			index++;
		if (s[index] == ',' && s[index + 1])
		{
			while (s[++index] && ft_isspace(s[index]) && s[index + 1])
				continue ;
			if (s[index + 1] && (!ft_isdigit(s[index])
					&& !ft_isspace(s[index])))
				return (0);
		}
	}
	if (!ft_isdigit(s[len - 1]))
		return (0);
	return (1);
}

static int	colour_parser(char *line, t_cubed *game)
{
	int	index;
	int	commas;

	index = 1;
	commas = 0;
	while (line[++index])
	{
		if (!ft_strchr("0123456789 , \t\r\v\f\n", line[index]))
			free_message(line, "Error\nColour codes are invalid!1\n", game);
		if (line[index] == ',')
			commas++;
	}
	if (commas != 2)
		free_message(line, "Error\nColour codes are invalid!2\n", game);
	if (!check_colour_codes(line))
		free_message(line, "Error\nColour codes are invalid!3\n", game);
	return (1);
}

static void	init_array(int *rgb, int size)
{
	int	index;

	index = 0;
	while (index < size)
		rgb[index++] = 0;
}

int	rgb_to_hex(char *line, t_cubed *game)
{
	int	index;
	int	j;
	int	rgb[3];

	if (!colour_parser(line, game))
		free_message(line, "Error\nColor codes are invalid!4\n", game);
	index = 0;
	j = 0;
	init_array(rgb, 3);
	while (line[index] && j < 3)
	{
		while (line[index] && (!ft_isdigit(line[index])))
			index++;
		while (ft_isdigit(line[index]))
		{
			rgb[j] = rgb[j] * 10;
			rgb[j] = rgb[j] + (line[index] - '0');
			index++;
		}
		if (rgb[j] > 255 || rgb[j] < 0)
			free_message(line, "Error\nColor codes are invalid!5\n", game);
		j++;
	}
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}
