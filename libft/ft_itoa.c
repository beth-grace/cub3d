/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:19:38 by cadlard           #+#    #+#             */
/*   Updated: 2024/03/12 14:44:33 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	count_digits(int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	sign_plus_zero(long *big_n, char *s0)
{
	if (*big_n < 0)
	{
		*s0 = '-';
		*big_n *= -1;
	}
	else if (*big_n == 0)
	{
		*s0 = '0';
	}
}

char	*ft_itoa(int n)
{
	long	big_n;
	size_t	i;
	size_t	len;
	char	*str;

	len = count_digits(n);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	big_n = (long)n;
	sign_plus_zero(&big_n, &str[0]);
	i = len;
	while (big_n != 0 && i > 0)
	{
		i--;
		str[i] = big_n % 10 + '0';
		big_n /= 10;
	}
	str[len] = '\0';
	return (str);
}
