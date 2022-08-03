/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack_twice.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:35:34 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/03 16:43:48 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_stack.h"

void	double_stack_rotate_both_twice(t_double_stack *dstack)
{
	double_stack_rotate_both(dstack);
	double_stack_rotate_both(dstack);
}

void	double_stack_rotate_a_twice(t_double_stack *dstack)
{
	double_stack_rotate_a(dstack);
	double_stack_rotate_a(dstack);
}

void	double_stack_rotate_b_twice(t_double_stack *dstack)
{
	double_stack_rotate_b(dstack);
	double_stack_rotate_b(dstack);
}
