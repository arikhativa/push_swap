/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack_get.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:43:16 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/03 16:49:11 by yrabby           ###   ########.fr       */
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
