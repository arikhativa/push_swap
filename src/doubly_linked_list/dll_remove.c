/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:26:07 by yoav              #+#    #+#             */
/*   Updated: 2022/07/26 12:34:42 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"

t_dll	*dll_remove_elem(t_dll *elem)
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

t_dll	*dll_remove_last_elem(t_dll *lst)
{
	t_dll	*next;

	if (!lst)
		return (NULL);
	next = lst->next;
	while (next)
	{
		lst = next;
		next = lst->next;
	}
	return (dll_remove_elem(lst));
}

t_dll	*dll_remove_first_elem(t_dll *lst)
{
	t_dll	*next;

	next = lst->next;
	if (!next)
		return (NULL);
	
	return (dll_remove_elem(lst));
}
