/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:33:50 by cadlard           #+#    #+#             */
/*   Updated: 2024/03/25 16:37:22 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	get_next_line_len(t_file *file)
{
	int		i;
	size_t	len;

	len = 0;
	i = file->idx;
	while (i < BUFFER_SIZE && file->buf[i])
	{
		len++;
		i++;
		if (file->buf[i - 1] == '\n')
			break ;
	}
	return (len);
}

// Makes a new str of new_size, then copies the data from the old str
// into the new str and frees the old str
char	*resize_str(char *str, size_t new_size, size_t old_len)
{
	size_t	i;
	char	*new;

	new = malloc(new_size * sizeof(char));
	if (new == NULL)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (i < new_size && i < old_len)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	free(str);
	return (new);
}

// Reads the next chunk of data into file, null terminates it if possible
// and sets the file idx back to zero
void	read_next_chunk(int fd, t_file *file)
{
	ssize_t	bytes_rd;

	file->idx = 0;
	bytes_rd = read(fd, file->buf, BUFFER_SIZE);
	if (bytes_rd < BUFFER_SIZE)
		file->buf[bytes_rd] = '\0';
}

// Updates the size of line and line_len since we haven't hit the end of the
// file or a newline
void	update_line_and_len(char **line, size_t *line_len, t_file *file)
{
	size_t	old_len;

	old_len = *line_len;
	*line_len += get_next_line_len(file);
	*line = resize_str(*line, *line_len + 1, old_len);
}
