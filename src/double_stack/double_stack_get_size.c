/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack_get_size.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:48:58 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/03 16:49:06 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_stack.h"

int	double_stack_get_size_a(t_double_stack *dstack)
{
	return (dstack->a->size);
}

int	double_stack_get_size_b(t_double_stack *dstack)
{
	return (dstack->b->size);
}
