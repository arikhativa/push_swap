/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:07:39 by yoav              #+#    #+#             */
/*   Updated: 2022/07/27 14:04:15 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dll.h"
#include "define.h"
#include "stack.h"
#include "double_stack.h"

int	double_stack_push_a(t_double_stack *dstack, int i)
{
	t_dll	*elem;

	elem = dll_create_elem(i);
	if (!elem)
		return (ERROR);
	stack_push(dstack->a, elem);
	return (SUCCESS);
}

void	double_stack_push_a_to_b(t_double_stack *dstack)
{
	t_dll	*elem;

	elem = stack_pop(dstack->a);
	stack_push(dstack->b, elem);	
}

void	double_stack_push_b_to_a(t_double_stack *dstack)
{
	t_dll	*elem;

	elem = stack_pop(dstack->b);
	stack_push(dstack->a, elem);	
}
