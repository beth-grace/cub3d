/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:13:32 by cadlard           #+#    #+#             */
/*   Updated: 2024/03/12 13:47:46 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*mapnew(void *content, void *(*f)(void *), void (*del)(void *))
{
	void	*f_content;
	t_list	*new;

	f_content = f(content);
	new = ft_lstnew(f_content);
	if (new == NULL)
	{
		del(f_content);
		return (NULL);
	}
	new->content = f_content;
	return (new);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*cur;
	t_list	*map_cur;

	if (lst == NULL)
		return (NULL);
	map = mapnew(lst->content, f, del);
	if (map == NULL)
		return (NULL);
	map_cur = map;
	cur = lst->next;
	while (cur)
	{
		map_cur->next = mapnew(cur->content, f, del);
		if (map_cur->next == NULL)
		{
			ft_lstclear(&map, del);
			return (NULL);
		}
		cur = cur->next;
		map_cur = map_cur->next;
	}
	map_cur->next = NULL;
	return (map);
}
