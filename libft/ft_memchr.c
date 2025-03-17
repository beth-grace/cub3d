/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:18:54 by cadlard           #+#    #+#             */
/*   Updated: 2024/03/07 13:23:35 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	const unsigned char		*mem;
	unsigned char			seq;

	mem = (const unsigned char *)s;
	seq = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (mem[i] == seq)
		{
			return ((void *)(mem + i));
		}
		i++;
	}
	return (NULL);
}
