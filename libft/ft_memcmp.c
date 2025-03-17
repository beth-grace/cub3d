/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:18:42 by cadlard           #+#    #+#             */
/*   Updated: 2024/03/07 13:23:53 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*m1;
	const unsigned char	*m2;

	m1 = (const unsigned char *)s1;
	m2 = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n - 1)
	{
		if (m1[i] != m2[i])
			return (m1[i] - m2[i]);
		i++;
	}
	return (m1[i] - m2[i]);
}
