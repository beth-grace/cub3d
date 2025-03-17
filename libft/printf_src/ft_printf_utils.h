/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:53:53 by cadlard           #+#    #+#             */
/*   Updated: 2024/03/26 13:10:11 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H
# include "ft_printf.h"

void	ft_printchar(char c, int *nprinted);
void	ft_printstr(char *str, int *nprinted);
void	put_conversion(va_list *ap, char conv, int *nprinted);
void	ap_putchar(va_list *ap, int *nprinted);
void	ap_putstr(va_list *ap, int *nprinted);
void	ap_put_hex_addr(va_list *ap, int *nprinted);
void	ap_putnbr(va_list *ap, int *nprinted);
void	ap_putunbr(va_list *ap, int *nprinted);
void	ap_put_hex(va_list *ap, int *nprinted, int isupper);

#endif
