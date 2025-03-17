/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:09:34 by cadlard           #+#    #+#             */
/*   Updated: 2024/03/26 12:45:37 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

static void	put_buf(char buf[10], int *nprinted)
{
	int	i;
	int	print_zeros;

	i = 0;
	print_zeros = 0;
	while (i < 10)
	{
		if (buf[i] == '0' && !print_zeros)
		{
			i++;
			continue ;
		}
		print_zeros = 1;
		ft_printchar(buf[i], nprinted);
		i++;
	}
	if (!print_zeros)
		ft_printchar('0', nprinted);
}

void	ap_putnbr(va_list *ap, int *nprinted)
{
	char	buf[10];
	long	n;
	int		i;

	n = va_arg(*ap, int);
	if (n < 0)
	{
		ft_printchar('-', nprinted);
		n *= -1;
	}
	i = 9;
	while (i >= 0)
	{
		buf[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	put_buf(buf, nprinted);
}

void	ap_putunbr(va_list *ap, int *nprinted)
{
	char			buf[10];
	unsigned int	n;
	int				i;

	n = va_arg(*ap, unsigned int);
	i = 9;
	while (i >= 0)
	{
		buf[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	put_buf(buf, nprinted);
}
