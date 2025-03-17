/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:19:00 by cadlard           #+#    #+#             */
/*   Updated: 2024/03/12 11:37:25 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	ndl_len;

	ndl_len = ft_strlen(needle);
	if (ndl_len == 0)
		return ((char *)(haystack));
	else if (ndl_len > len)
		return (NULL);
	i = 0;
	while (haystack[i] && i <= len - ndl_len)
	{
		if (ft_strncmp(haystack + i, needle, ndl_len) == 0)
		{
			return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
