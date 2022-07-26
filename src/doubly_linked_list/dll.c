/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:47:10 by yoav              #+#    #+#             */
/*   Updated: 2022/07/26 12:26:13 by yoav             ###   ########.fr       */
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
	t_dll	*next;

	while (lst)
	{
		next = lst->next;
		dll_free_elem(lst);
		lst = next;
	}
}
