/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hexnumbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:35:26 by cadlard           #+#    #+#             */
/*   Updated: 2024/03/26 13:21:03 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

static void	put_hex_buf(char buf[16], int *nprinted)
{
	int	i;
	int	print_zeros;

	print_zeros = 0;
	i = 0;
	while (i < 16)
	{
		if (buf[i] != '0')
		{
			ft_printchar(buf[i], nprinted);
			print_zeros = 1;
		}
		else if (print_zeros)
		{
			ft_printchar(buf[i], nprinted);
		}
		i++;
	}
	if (print_zeros == 0)
		ft_printchar('0', nprinted);
}

void	ap_put_hex(va_list *ap, int *nprinted, int isupper)
{
	const char			*hex_digits = "0123456789abcdef";
	char				buf[16];
	unsigned long long	num;
	int					i;

	num = va_arg(*ap, int);
	i = 15;
	while (i >= 8)
	{
		buf[i] = hex_digits[num % 16];
		if (isupper)
			buf[i] = ft_toupper(buf[i]);
		num /= 16;
		i--;
	}
	while (i >= 0)
	{
		buf[i] = '0';
		i--;
	}
	put_hex_buf(buf, nprinted);
}

void	ap_put_hex_addr(va_list *ap, int *nprinted)
{
	const char			*hex_digits = "0123456789abcdef";
	char				buf[16];
	unsigned long long	num;
	int					i;

	num = va_arg(*ap, unsigned long long);
	i = 15;
	while (i >= 0)
	{
		buf[i] = hex_digits[num % 16];
		num /= 16;
		i--;
	}
	ft_printstr("0x", nprinted);
	put_hex_buf(buf, nprinted);
}
