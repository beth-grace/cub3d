/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:05:08 by cadlard           #+#    #+#             */
/*   Updated: 2024/03/12 13:59:11 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s1, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (s1[i])
	{
		if ((i == 0 || s1[i - 1] == c) && s1[i] != c)
			words++;
		i++;
	}
	return (words);
}

static int	alloc_word(char **dst, char const *s1, char c, int i)
{
	int	len;

	len = 0;
	while (s1[i] && s1[i] != c)
	{
		i++;
		len++;
	}
	*dst = malloc((len + 1) * sizeof(char));
	return (len);
}

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static char	**the_loop(char const *s1, char c, int nwords, char **split)
{
	int	i;
	int	cur_word;
	int	cur_word_len;

	i = 0;
	cur_word = 0;
	while (cur_word < nwords)
	{
		if (!((i == 0 || s1[i - 1] == c) && s1[i] != c))
		{
			i++;
			continue ;
		}
		cur_word_len = alloc_word(&split[cur_word], s1, c, i) + 1;
		if (split[cur_word] == NULL)
		{
			free_split(split);
			return (NULL);
		}
		ft_strlcpy(split[cur_word], s1 + i, cur_word_len);
		i += cur_word_len;
		cur_word++;
	}
	split[cur_word] = NULL;
	return (split);
}

char	**ft_split(char const *s1, char c)
{
	int		nwords;
	char	**split;

	nwords = count_words(s1, c);
	split = malloc((nwords + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	split = the_loop(s1, c, nwords, split);
	return (split);
}
