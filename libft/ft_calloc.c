/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:05:45 by cadlard           #+#    #+#             */
/*   Updated: 2024/03/07 13:23:17 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	nbytes;
	void	*mem;

	nbytes = count * size;
	mem = malloc(nbytes);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, nbytes);
	return (mem);
}
