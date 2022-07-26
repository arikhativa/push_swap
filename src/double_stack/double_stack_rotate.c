/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:21:31 by yoav              #+#    #+#             */
/*   Updated: 2022/07/26 14:22:29 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_stack.h"
#include "stack.h"

void	double_stack_rotate_a(t_double_stack *dstack)
{
	stack_rotate(dstack->a);
}

void	double_stack_rotate_b(t_double_stack *dstack)
{
	stack_rotate(dstack->b);
}
