/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:44:44 by yoav              #+#    #+#             */
/*   Updated: 2022/07/26 13:56:41 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "define.h"
#include "dll.h"

void	stack_push(t_stack *s, t_dll *elem)
{
	t_dll	**list;

	list = stack_get_list(s);
	dll_add_last(list, elem);
	++s->size;
}

t_dll	*stack_pop(t_stack *s)
{
	t_dll	**list;
	t_dll	*elem;

	if (!s->size)
		return (NULL);
	if (1 == s->size)
	{
		elem = s->lst;
		s->lst = NULL;
		--s->size;
		return (elem);
	}
	--s->size;
	list = stack_get_list(s);
	return (dll_remove_last_elem(*list));
}

void	stack_rotate(t_stack *s)
{
	t_dll	**list;
	t_dll	*last;

	list = stack_get_list(s);
	last = dll_remove_last_elem(*list);
	dll_add_before(*list, last);
}
