/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:44:23 by cadlard           #+#    #+#             */
/*   Updated: 2024/03/26 14:06:34 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		nprinted;
	int		i;

	va_start(ap, str);
	nprinted = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1])
			{
				put_conversion(&ap, str[i + 1], &nprinted);
				i++;
			}
		}
		else
		{
			ft_printchar(str[i], &nprinted);
		}
		i++;
	}
	va_end(ap);
	return (nprinted);
}
