/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:44:24 by cadlard           #+#    #+#             */
/*   Updated: 2024/03/11 11:52:39 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	put_buf(char buf[10], int fd)
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
		write(fd, buf + i, 1);
		i++;
	}
	if (!print_zeros)
		write(fd, "0", 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	buf[10];
	int		i;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	i = 9;
	while (i >= 0)
	{
		buf[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	put_buf(buf, fd);
}
