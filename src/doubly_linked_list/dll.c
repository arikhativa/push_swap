/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:47:10 by yoav              #+#    #+#             */
/*   Updated: 2022/07/26 12:00:03 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"
#include "libft.h"

t_dll	*dll_create_elem(int value)
{
	t_dll	*elem;

	elem = ft_calloc(1, sizeof(t_dll));
	if (!elem)
		return (NULL);
	elem->value = value;
	return (elem);
}

void	dll_free_elem(t_dll *elem)
{
	ft_bzero(elem, sizeof(t_dll));
	free(elem);
}

void	dll_clear_list(t_dll *lst)
{
	
}

t_dll	*list_remove_elem(t_dll *elem)
{
	t_dll	*next;
	t_dll	*prev;

	prev = elem->prev;
	next = elem->next;
	if (prev)
		prev->next = next;
	if (next)
		next->prev = prev;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}
