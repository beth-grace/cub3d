/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:41:43 by cadlard           #+#    #+#             */
/*   Updated: 2024/05/23 12:51:58 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t len);
size_t	get_next_line_len(t_file *file);
char	*resize_str(char *str, size_t new_size, size_t old_len);
void	read_next_chunk(int fd, t_file *file);
void	update_line_and_len(char **line, size_t *line_len, t_file *file);

// Reads a line from file into line
static char	*read_line(char *line, size_t line_len, t_file *file, int fd)
{
	int	i;

	i = 0;
	while (1)
	{
		if (file->idx >= BUFFER_SIZE || (fd == 0 && !file->buf[file->idx]))
		{
			read_next_chunk(fd, file);
			update_line_and_len(&line, &line_len, file);
			if (line == NULL)
				return (NULL);
		}
		if (file->buf[file->idx] == '\0')
		{
			file->idx = BUFFER_SIZE;
			break ;
		}
		line[i] = file->buf[file->idx];
		file->idx++;
		if (line[i] == '\n')
			break ;
		i++;
	}
	line[line_len] = '\0';
	return (line);
}

static char	*get_line(int fd, t_file *file)
{
	size_t	line_len;
	char	*line;

	if (file->idx >= BUFFER_SIZE || (fd == 0 && file->buf[file->idx] == '\0'))
	{
		read_next_chunk(fd, file);
	}
	line_len = get_next_line_len(file);
	if (line_len == 0)
		return (NULL);
	line = malloc((line_len + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	line = read_line(line, line_len, file, fd);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_file	file = {.idx = BUFFER_SIZE};
	char			*line;

	if (read(fd, 0, 0) == -1)
	{
		file.idx = BUFFER_SIZE;
		ft_bzero(file.buf, BUFFER_SIZE);
		return (NULL);
	}
	line = get_line(fd, &file);
	if (line == NULL)
	{
		file.idx = BUFFER_SIZE;
		ft_bzero(file.buf, BUFFER_SIZE);
	}
	return (line);
}
