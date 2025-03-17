/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putcharacters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:44:32 by cadlard           #+#    #+#             */
/*   Updated: 2024/03/26 12:36:21 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	ap_putchar(va_list *ap, int *nprinted)
{
	unsigned int	c;

	c = va_arg(*ap, unsigned int);
	ft_printchar((char)c, nprinted);
}

void	ap_putstr(va_list *ap, int *nprinted)
{
	char	*str;

	str = va_arg(*ap, char *);
	if (str != NULL)
	{
		ft_printstr(str, nprinted);
	}
	else
	{
		ft_printstr("(null)", nprinted);
	}
}
