/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:49:08 by yoav              #+#    #+#             */
/*   Updated: 2022/07/28 09:15:51 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "stack.h"
#include "dll.h"

// TODO = think on empty list
int	stack_get_second_to_top_value(t_stack *s)
{
	t_dll *last_elem;

	last_elem = dll_get_last_elem(*stack_get_list(s));
	if (last_elem->prev)
		return (last_elem->prev->value);
	return (ERROR);
}

// TODO = think on empty list
int	stack_get_top_value(t_stack *s)
{
	t_dll *last_elem;

	last_elem = dll_get_last_elem(*stack_get_list(s));
	if (last_elem)
		return (last_elem->value);
	return (ERROR);
}

t_dll	**stack_get_list(t_stack *s)
{
	return (&(s->lst));
}

int	stack_get_size(t_stack *s)
{
	return (s->size);
}
