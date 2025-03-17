/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:06:30 by cadlard           #+#    #+#             */
/*   Updated: 2024/03/12 14:57:49 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	char		chr;
	const char	*res;

	chr = (char)c;
	res = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == chr)
		{
			res = s + i;
		}
		i++;
	}
	if (s[i] == chr)
	{
		res = s + i;
	}
	return ((char *)(res));
}
