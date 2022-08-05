/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack_pop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:39:13 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/05 14:15:28 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_stack.h"

t_dll	*double_stack_pop_a(t_double_stack *dstack)
{
	return (stack_pop(dstack->a));
}

t_dll	*double_stack_pop_b(t_double_stack *dstack)
{
	return (stack_pop(dstack->b));
}
