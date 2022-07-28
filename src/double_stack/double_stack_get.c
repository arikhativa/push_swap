/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack_get.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:43:16 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/28 09:27:42 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_stack.h"

int	double_stack_get_second_to_top_value_a(t_double_stack *dstack)
{
	return (stack_get_second_to_top_value(dstack->a));
}

int	double_stack_get_second_to_top_value_b(t_double_stack *dstack)
{
	return (stack_get_second_to_top_value(dstack->b));
}

int	double_stack_get_top_value_a(t_double_stack *dstack)
{
	return (stack_get_top_value(dstack->a));
}

int	double_stack_get_top_value_b(t_double_stack *dstack)
{
	return (stack_get_top_value(dstack->b));
}

int	double_stack_get_size_a(t_double_stack *dstack)
{
	return (dstack->a->size);
}

int	double_stack_get_size_b(t_double_stack *dstack)
{
	return (dstack->b->size);
}
