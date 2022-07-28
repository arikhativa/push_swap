/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:21:31 by yoav              #+#    #+#             */
/*   Updated: 2022/07/28 13:06:37 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_stack.h"

void	double_stack_rotate_both(t_double_stack *dstack)
{
	ft_printf("rr\n");
	stack_rotate(dstack->a);
	stack_rotate(dstack->b);
}

void	double_stack_rotate_a(t_double_stack *dstack)
{
	ft_printf("ra\n");
	stack_rotate(dstack->a);
}

void	double_stack_rotate_b(t_double_stack *dstack)
{
	ft_printf("rb\n");
	stack_rotate(dstack->b);
}
