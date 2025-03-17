/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:51:24 by cadlard           #+#    #+#             */
/*   Updated: 2024/03/26 13:43:17 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	ft_printchar(char c, int *nprinted)
{
	if (*nprinted == -1)
		return ;
	if (write(STDOUT, &c, 1) == -1)
		*nprinted = -1;
	else
		*nprinted = *nprinted + 1;
}

void	ft_printstr(char *str, int *nprinted)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_printchar(str[i], nprinted);
		i++;
	}
}

void	put_conversion(va_list *ap, char conv, int *nprinted)
{
	if (conv == 'c')
		ap_putchar(ap, nprinted);
	else if (conv == 's')
		ap_putstr(ap, nprinted);
	else if (conv == 'p')
		ap_put_hex_addr(ap, nprinted);
	else if (conv == 'd')
		ap_putnbr(ap, nprinted);
	else if (conv == 'i')
		ap_putnbr(ap, nprinted);
	else if (conv == 'u')
		ap_putunbr(ap, nprinted);
	else if (conv == 'x')
		ap_put_hex(ap, nprinted, 0);
	else if (conv == 'X')
		ap_put_hex(ap, nprinted, 1);
	else if (conv == '%')
		ft_printchar('%', nprinted);
}
