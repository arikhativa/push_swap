/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:03:46 by yoav              #+#    #+#             */
/*   Updated: 2022/07/26 12:34:58 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"

void	dll_add_after(t_dll *lst, t_dll *new_elem)
{
	t_dll	*next;

	next = lst->next;
	lst->next = new_elem;
	new_elem->next = next;
	new_elem->prev = lst;
}

void	dll_add_before(t_dll *lst, t_dll *new_elem)
{
	t_dll	*next;

	dll_add_after(lst, new_elem);
	next = lst->next;
	swap(&(lst->value), &(next->value));
}

void	dll_add_last(t_dll **lst, t_dll *new_elem)
{
	t_dll	*elem;
	t_dll	*next;

	if (!(*lst))
	{
		*lst = new_elem;
		return ;
	}
	elem = *lst;
	next = elem->next;
	while (next)
	{
		elem = next;
		next = elem->next;
	}
	dll_add_after(elem, new_elem);
}
