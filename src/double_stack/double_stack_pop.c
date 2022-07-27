/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack_pop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:39:13 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/27 13:40:37 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dll.h"
#include "define.h"
#include "stack.h"
#include "double_stack.h"

t_dll	*double_stack_pop_a(t_double_stack *dstack)
{
	return (stack_pop(dstack->a));
}

t_dll	*double_stack_pop_b(t_double_stack *dstack)
{
	return (stack_pop(dstack->b));
}
