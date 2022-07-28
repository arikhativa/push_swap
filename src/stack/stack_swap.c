/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 09:21:29 by yoav              #+#    #+#             */
/*   Updated: 2022/07/28 09:26:53 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_swap_top(t_stack *s)
{
	t_dll	*top;
	t_dll	*sec_to_top;

	if (2 <= s->size)
	{
		top = dll_remove_last_elem(s->lst);
		sec_to_top = dll_remove_last_elem(s->lst);
		if (2 == s->size)
			s->lst = top;
		else
			stack_push(s, top);
		stack_push(s, sec_to_top);
	}
}
