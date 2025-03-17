/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:52:20 by cadlard           #+#    #+#             */
/*   Updated: 2024/03/11 11:09:45 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_contains(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	trimmed_len(char const *s1, char const *set, int *end_idx)
{
	int	i;
	int	j;
	int	len;
	int	not_len;

	len = ft_strlen(s1);
	not_len = 0;
	i = 0;
	while (str_contains(set, s1[i]))
	{
		not_len++;
		i++;
	}
	j = len - 1;
	while (j > i - 1 && str_contains(set, s1[j]))
	{
		not_len++;
		j--;
	}
	*end_idx = j + 1;
	return (len - not_len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		t_idx;
	int		end_idx;
	char	*trimmed;

	trimmed = malloc((trimmed_len(s1, set, &end_idx) + 1) * sizeof(char));
	if (trimmed == NULL)
		return (NULL);
	i = 0;
	while (str_contains(set, s1[i]))
		i++;
	t_idx = 0;
	while (i < end_idx)
	{
		trimmed[t_idx] = s1[i];
		t_idx++;
		i++;
	}
	trimmed[t_idx] = '\0';
	return (trimmed);
}
