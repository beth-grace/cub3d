/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrlst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:52:17 by cadlard           #+#    #+#             */
/*   Updated: 2024/05/27 15:47:31 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "arrlst.h"

// arrlst.arr is set to NULL on fail
t_arrlst	arrlst_create(size_t capacity)
{
	t_arrlst	lst;

	lst.arr = malloc(capacity * sizeof(void *));
	if (lst.arr == NULL)
		capacity = 0;
	else
		lst.capacity = capacity;
	lst.len = 0;
	return (lst);
}

void	arrlst_delete(t_arrlst *lst, void (*del)(void *))
{
	size_t	i;

	i = 0;
	while (i < lst->len)
	{
		if (lst->arr[i])
			del(lst->arr[i]);
		i++;
	}
	lst->len = 0;
	if (lst->arr)
		free(lst->arr);
	lst->arr = NULL;
	lst->capacity = 0;
}

static inline void	arr_cpy(void **dst, void **src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
}

// !!! will free lst on fail !!!
// lst.arr is set to NULL on fail
void	arrlst_push(t_arrlst *lst, void *data, void (*del)(void *))
{
	size_t	new_cap;
	void	**new_arr;

	if (lst->len < lst->capacity && lst->capacity > 0)
	{
		lst->arr[lst->len] = data;
		lst->len++;
		return ;
	}
	new_cap = lst->capacity * 2;
	if (lst->capacity <= 0)
		new_cap = 1;
	new_arr = malloc(new_cap * sizeof(void *));
	if (new_arr == NULL)
	{
		arrlst_delete(lst, del);
		return ;
	}
	arr_cpy(new_arr, lst->arr, lst->len);
	if (lst->arr)
		free(lst->arr);
	lst->arr = new_arr;
	lst->capacity = new_cap;
	lst->arr[lst->len] = data;
	lst->len++;
}

void	*arrlst_pop(t_arrlst *lst)
{
	void	*pop;

	if (lst->len <= 0)
		return (NULL);
	pop = lst->arr[lst->len - 1];
	lst->len--;
	return (pop);
}
