/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrlst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:54:43 by cadlard           #+#    #+#             */
/*   Updated: 2024/05/27 15:47:39 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRLST_H
# define ARRLST_H

// unused
# ifndef ARRLST_NEW_CAPACITY_CAP
#  define ARRLST_NEW_CAPACITY_CAP 4096
# endif

/*
 * void		**arr -> an indexable arr of void pointers
 * size_t	capacity ->	current capacity of array, if len > capacity then
 * 						capacity is doubled
 * size_t	len -> current amount of elements stored in arr, use for
 * 					iterating over arr
 */
typedef struct s_arrlst
{
	/* public members */
	void	**arr;
	/* private members; can read values but do not change them */
	size_t	capacity;
	size_t	len;
}			t_arrlst;

// arrlst.arr is set to NULL on fail
t_arrlst	arrlst_create(size_t capacity);

void		arrlst_delete(t_arrlst *lst, void (*del)(void *));

// !!! will free lst on fail !!!
// lst.arr is set to NULL on fail
void		arrlst_push(t_arrlst *lst, void *data, void (*del)(void *));

// returns NULL if lst is empty
void		*arrlst_pop(t_arrlst *lst);

#endif
